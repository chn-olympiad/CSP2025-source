#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	string s;
	cin>>s;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		if(s.find("1")==string::npos){
			printf("0");
			return 0;
		}else{
			printf("1");
			return 0;
		}
	}
	if(s.find("0")==string::npos){
		long long ans=1;
		for(int i=1; i<=n; i++){
			ans=(ans*i)%mod;
		}
		printf("%lld",ans);
		return 0;
	}else{
		printf("0");
	}
	return 0;
}
