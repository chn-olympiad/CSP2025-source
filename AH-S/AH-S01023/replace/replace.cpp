#include<bits/stdc++.h>
using namespace std;
int n,q;
bool test=1;
string s[200005][2],t,d;
string read(){
    char tmp;
    string ret;
    while(tmp=getchar()){
        if(tmp!=' '&&tmp!='\n')ret+=tmp;
        else return ret;
    }
}
void solveA(){
    int b[200005][2],l[200005],r[200005],p[200005];
    for(int i=1;i<=n;i++){
        for(int j=0;j<s[i][0].size();j++){
            if(s[i][0][j]=='b')b[i][0]=j;
            if(s[i][1][j]=='b')b[i][1]=j;
        }
        p[i]=b[i][0]-b[i][1];
        l[i]=b[i][0]-1;
        r[i]=s[i][0].size()-b[i][0]-1;
    }
    while(q--){
        t=read(),d=read();
        if(t.size()!=d.size()){
            cout<<"0\n";
            continue;
        }
        int st,ed,cnt=0;
        for(int j=0;j<t.size();j++){
            if(t[j]=='b')st=j;
            if(d[j]=='b')ed=j;
        }
        for(int i=1;i<=n;i++){
            if(st-ed==p[i]&&st-1>=l[i]&&t.size()-st-1>=r[i])cnt++;
        }
        cout<<cnt<<endl;
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    getchar();
    for(int i=1;i<=n;i++){
        s[i][0]=read(),s[i][1]=read();
        for(int j=0;j<s[i][0].size();j++){
            if(s[i][0][j]!='a'&&s[i][0][j]!='b'||s[i][1][j]!='a'&&s[i][1][j]!='b'){
                test=0;
                break;
            }
        }
    }
    if(test){
        solveA();
        return 0;
    }
    while(q--){
        t=read(),d=read();
        if(t.size()!=d.size()){
            cout<<"0\n";
            continue;
        }
        int len=t.size(),cnt=0,l=-1,r=-1;
        for(int i=0;i<len;i++){
            if(t[i]!=d[i]){
                l=i;
                break;
            }
        }
        for(int i=len-1;i>=0;i--){
            if(t[i]!=d[i]){
                r=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            bool flag=0;
            if(s[i][0].size()>len||s[i][0].size()<r-l+1)continue;
            int ls=s[i][0].size();
            for(int j=max(ls-1,r);j<len;j++){
                bool okay=1;
                if(j-ls>=l)break;
                for(int k=0;k<ls;k++){
                        //if(i==3)cout<<ls<<" "<<s[i][0][k]<<" "<<t[j-ls+k+1]<<" "<<s[i][1][k]<<" "<<d[j-ls+k+1]<<endl;
                    if(s[i][0][k]!=t[j-ls+k+1]||s[i][1][k]!=d[j-ls+k+1]){
                        okay=0;
                        break;
                    }
                }
                //cout<<j<<" "<<okay<<endl;
                if(okay){
                    flag=1;
                    break;
                }
            }
            //cout<<i<<" "<<flag<<endl;
            cnt+=flag;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
