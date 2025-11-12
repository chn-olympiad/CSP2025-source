#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c;
	scanf("%d%d",&n,&m);
	cin>>s;
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		if(c==0){
			sum++;
		}
	}
	if(n-sum<m){
		printf("0\n");
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	printf("%lld",ans);
	return 0;
}
