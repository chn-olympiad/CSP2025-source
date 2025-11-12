#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
const int N=1e6+10;
struct edge{
    ll on,tw,th,bh;
}ar[N];
ll n,T,dp[3][N],ans=0;
ll f[N];
string st,str,strs[N],strss[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>T;
    f(i,1,n)cin>>strs[i]>>strss[i];
    while(T--){
        cin>>st>>str;
        ans=0;
        st=" "+st;
        str=str;
        ll rp=st.size(),pr=str.size();
        if(rp!=pr+1){
            cout<<0<<endl;
            continue;
        }
        f(i,1,n){
            ll baoya=strs[i].size();
            f(j,1,rp-baoya){
                string hk=st.substr(1,j-1),hk1=st.substr(max(j,1),baoya),hk2=st.substr(j+baoya,rp-baoya-j);
                
                if(hk1==strs[i]){
                	string jk=hk+strss[i]+hk2;
                	if(jk==str){
                		ans++;
                        break;
					}
				} 
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}