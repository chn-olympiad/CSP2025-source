#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
int t,n,m,k,ans,x,xx,y,a[1000000],b[1000000];
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m;
        cin>>s;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=i;
        }
        int c=0,cc=0,ans=0;
        do{
            c=0,cc=0;
            for(int i=1;i<=n;i++){
                if(s[i-1]=='0'){
                    if(a[b[i]]<=c){
                        c++;
                    }
                    else{
                        cc++;
                    }
                }
                else{
                    c++;
                }
            }
            if(cc>=m) ans++;
        }while(next_permutation(b+1,b+n+1));
        cout<<ans<<endl;
    }
    return 0;
}
