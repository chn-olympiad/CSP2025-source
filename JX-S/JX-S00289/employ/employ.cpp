#include<bits/stdc++.h>
using namespace std;
char s[505];
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	long long ans=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		if(c[i]<=cnt){
			cnt++;
			continue;
		}
	}
	if(n-cnt<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	printf("%lld",ans);
	return 0;
}
