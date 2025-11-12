#include<bits/stdc++.h>
using namespace std;
string s[200005][5];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    string t1,t2;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            cin>>s[i][j];
        }
    }
    while(q--){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        int ans=0;
        for(int i=0;i<t1.size();i++){
            for(int j=1;j<=n;j++){
                bool flag=1;
                for(int k=0;k<s[j][1].size();k++){
                    if(i+k>=t1.size()||s[j][1][k]!=t1[i+k]||s[j][2][k]!=t2[i+k]){
                        flag=0;
                        break;
                    }
                }
                for(int k=0;k<i;k++){
                    if(t1[k]!=t2[k]){
                        flag=0;
                        break;
                    }
                }
                for(int k=i+s[j][1].size();k<t1.size();k++){
                    if(t1[k]!=t2[k]){
                        flag=0;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
