#include <bits/stdc++.h>
using namespace std;
int s[510]{};
int n,m;
int c[510]{};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int g[510]{};
	int cc=0;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		s[i]=a-'0';
		if(m==n&&s[i]==0){
			printf("0");
			return 0;
		}
		if(s[i]==0){
			cc=1;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(!cc&&n>10){
		long long s1=1;
		long long nn=n;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				nn--;
			}
		}
		n=nn;
		for(long long i=1;i<=n;i++){
			s1*=i;
			s1%=998244353;
		}
		printf("%lld",s1);
		return 0;
	}
	int a[n+10]{};
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	int ans=0;
	do{
		int s2=0,s1=0;
		for(int i=1;i<=n;i++){
			if(s1>=c[a[i]]){
				s1++;
				continue;
			}
			if(!s[i]){
				s1++;
			}
			else{
				s2++;
			}
		}
		if(s2>=m){
			ans++;
			ans%=998244353;
		}
	}while(next_permutation(a+1,a+n+1));
	printf("%d",ans);
	return 0;
}
