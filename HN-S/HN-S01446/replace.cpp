#include<bits/stdc++.h>
using namespace std;
bool ts;
int n,q,wb[200005][2];
string s[200005][3],ha[200005],dh[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> s[i][1] >> s[i][2];
        for(int j=0;j<s[i][1].size();j++){
            if(s[i][1][j]!='a'&&s[i][1][j]!='b'){
                ts=1;
            }
            if(s[i][1][j]=='b'){
                wb[i][1]=j+1;
            }
            if(s[i][2][j]=='b'){
                wb[i][2]=j+1;
            }
        }
    }
    if(!ts){
        while(q--){
            string t,tt;
            cin >> t >> tt;
            if(t.size()!=tt.size()){
                cout << "0\n";
                continue;
            }
            int nb,nnb;
            for(int i=0;i<t.size();i++){
                if(t[i]=='b')nb=i+1;
                if(tt[i]=='b')nnb=i+1;
            }
            int ans=0;
            for(int j=1;j<=n;j++){
                if(nb>=wb[j][1]&&(t.size()-nb)>=(s[j][1].size()-wb[j][1])){
                    if(nnb>=wb[j][2]&&(t.size()-nnb)>=(s[j][2].size()-wb[j][2])){
                        if(nnb-nb==wb[j][2]-wb[j][1]){
                            ans++;
                        }
                    }
                }
            }
            cout << ans << '\n';
        }
        return 0;
    }
    if(n>=100005){
        while(q--){
            cout << "0\n";
        }
        return 0;
    }
    while(q--){
        string t,tt;
        cin >> t >> tt;
        if(t.size()!=tt.size()){
            cout << "0\n";
            continue;
        }
        int m=t.size();
        ha[0]=t[0];
        for(int i=1;i<m;i++){
            ha[i]=ha[i-1]+t[i];
        }
        dh[m-1]=t[m-1];
        for(int i=m-2;i>=0;i--){
            dh[i]=t[i]+dh[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j+s[i][1].size()-1<m;j++){
                string lst=s[i][2];
                bool flag=1;
                for(int k=0;k<s[i][1].size();k++){
                    if(s[i][1][k]!=t[j+k]){
                        // cout << s[i][1][k] << ' ' << t[j+k] << '\n';
                        flag=0;
                        break;
                    }
                }
                if(!flag)continue;
                if(j){
                    lst=ha[j-1]+lst;
                    // cout << lst << ' ';
                }
                if(j+s[i][1].size()<m){
                    lst=lst+dh[j+s[i][1].size()];
                    // cout << lst << ' ';
                }
                // cout << '\n';
                if(lst==tt){
                    ans++;
                    // cout << i << ' ' << j << '\n';
                }else{
                    // cout << lst << ' ';
                }
            }
            // cout <<'\n';
        }
        cout << ans << '\n';
    }
    return 0;
}