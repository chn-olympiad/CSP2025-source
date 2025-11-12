#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
const int N=510;
int s[N];
int c[N];
char t;
int a[N];
void xyb(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int main(){
	xyb();
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>t;
		s[i]=t-'0';
		if(s[i]!=1)flag=false;
	}
	int cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i])cnt0++;
	}
	
	if(flag){
		long long ans=1;
		if(m>n-cnt0){
			for(int i=1;i<=m;i++){
				ans*=i;
				ans%=998244353;
			}
			for(int i=1;i<=n-m;i++){
				ans*=i;
				ans%=998244353;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
		}
		printf("%lld",ans%998244353);
		return 0;
	}
	
	for(int i=1;i<=n;i++)a[i]=i;
	long long ans=0;
	do{
		int fail=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(!s[i])fail++;
			else{
				if(fail>=c[a[i]])fail++;
				else cnt++;
			}
		}
		if(cnt>=m){
			ans++;
			if(ans==998244353)ans-=998244353;
		}
	}while(next_permutation(a+1,a+1+n));
	printf("%lld",ans);
	return 0;
}
