#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],id[N],ans;
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin>>n>>m>>s+1;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=10){
        for(int i=1;i<=n;i++) id[i]=i;
        do{
            int s=0;
            for(int i=1;i<=n;i++){
                if(s>=a[id[i]]||::s[i]==48) s++;
            }
            if(s<=n-m) ans++;
        }while(next_permutation(id+1,id+1+n));
        cout<<ans%mod<<'\n';
        return 0;
    }
	return 0;
}