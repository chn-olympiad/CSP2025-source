#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=505,mod=998244353;

int c[N],a[N],f[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef local
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=i;
	}
	if(n<=10){
		int sum=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				f[i]=0;
			}
			for(int i=1;i<=n;i++){
				if(f[i-1]>=c[a[i]]){
					f[i]=f[i-1]+1;
					continue;
				}
				if(s[i-1]=='1'){
					f[i]=f[i-1];
					cnt++;
				}
				else{
					f[i]=f[i-1]+1;
				}
			}
			if(cnt>=m){
				sum++;
			}
		}while(next_permutation(a+1,a+n+1));
		cout<<sum;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(c[i]){
			sum++;
		}
	}
	int ans=1;
	for(int i=1;i<=sum;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}

