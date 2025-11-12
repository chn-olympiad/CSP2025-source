#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000;
int n,m,ans,cnt,c[N],x[N];
string s;
int32_t main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> s;
    for(auto c:s)cnt+=c=='1';
    if(cnt<m)return cout << 0,0;
    for(int i=1;i<=n;i++)cin >> c[i],x[i]=i;;
    if(1){

        do{
            int fd=0;
            for(int i=1;i<=n;i++){
                if(fd>=c[x[i]]||s[i-1]=='0'){
                    fd++;
                    continue;
                }
            }
            if(n-fd>=m)(++ans)%=998244353;
        }while(next_permutation(x+1,x+n+1));
        cout << ans;
        return 0;
    }

    return 0;
}
