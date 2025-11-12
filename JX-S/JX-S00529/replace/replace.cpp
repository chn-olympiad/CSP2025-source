#include <bits/stdc++.h>
using namespace std;
int n,q,gg,cha[200005];
string s[200005][5],t[5];
vector<string> v[200005];
map<string,int>u;
long long ans;
int pan(string s){
    int suma=0,sumb=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a') suma++;
        if(s[i]=='b') sumb++;
    }
    if(suma+sumb==s.size()&&sumb==1) return 1;
    return 0;
}
int wei(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='b') return i;
    }
}
int ppp[200005][5];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> s[i][1] >> s[i][2];
        if(pan(s[i][1])==1&&pan(s[i][2])==1){
            gg++;
            ppp[i][1]=wei(s[i][1]),ppp[i][2]=wei(s[i][2]);
            cha[i]=(ppp[i][2]-ppp[i][1]);
        }
        if(u[s[i][1]]==0) u[s[i][1]]=i;
        v[u[s[i][1]]].push_back(s[i][2]);
    }
    while(q--){
        ans=0;
        cin >> t[1] >> t[2];
        if(t[1].size()!=t[2].size()){
            cout << "0" << endl;
            continue;
        }
        if(pan(t[1])==1&&pan(t[2])==1){
            int aaa=wei(t[1]),bbb=wei(t[2]);
            int ll=bbb-aaa;
            for(int i=1;i<=n;i++){
                if(ll==cha[i]&&bbb>=ppp[i][2]&&aaa>=ppp[i][1]){
                    if(t[1].size()-aaa>=s[i][1].size()-ppp[i][1]&&t[2].size()-bbb>=s[i][2].size()-ppp[i][2]) ans++;
                }
            }
            cout << ans << endl;
            continue;
        }
        int qian=0,hou=0;
        for(int i=0;i<t[1].size();i++){
            if(t[1][i]!=t[2][i]) break;
            qian++;
        }
        for(int i=t[1].size()-1;i>=0;i--){
            if(t[1][i]!=t[2][i]) break;
            hou++;
        }
        string flaga="",flagb="";
        for(int i=qian;i<=t[1].size()-1-hou;i++){
            flaga+=t[1][i],flagb+=t[2][i];
        }
        string flagqian[qian+5+t[1].size()],flaghou[hou+5+t[1].size()];
        for(int i=0;i<qian+5+t[1].size();i++) flagqian[i]="",flaghou[i]="";
        if(qian>=1) flagqian[qian-1]=t[1][qian-1];
        if(hou>=1) flaghou[t[1].size()-hou]=t[1][t[1].size()-hou];
        for(int i=qian-2;i>=0;i--) flagqian[i]=t[1][i]+flagqian[i+1];
        for(int i=t[1].size()-hou+1;i<t[1].size();i++) flaghou[i]=flaghou[i-1]+t[1][i];
        for(int i=0;i<=qian;i++){
            for(int j=t[1].size()-1-hou;j<=(t[1].size()-1);j++){
                string x=flagqian[i]+flaga+flaghou[j],y=flagqian[i]+flagb+flaghou[j];
                for(int k=0;k<v[u[x]].size();k++){
                    if(v[u[x]][k]==y) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
