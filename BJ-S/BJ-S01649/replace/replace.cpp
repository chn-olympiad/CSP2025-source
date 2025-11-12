#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
using namespace std;
string s[105][2];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;    
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    } 
    while(q--){
        string a,b;
        cin>>a>>b;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n-s[i][0].size()+1;j++){
                bool flag=1;
                for(int k=j;k<=j+s[i][0].size()-1;k++){
                    if(a[k]!=s[i][0][k-j]){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    string c=a;
                    for(int k=j;k<=j+s[i][0].size()-1;k++){
                        c[k]=s[i][1][k-j];
                    }
                    if(c==b) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}