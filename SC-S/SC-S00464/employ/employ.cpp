#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
bool s[505];
int c[505];
int tat0[505],p1[505];
int lgo[505],rgo[505];
long long ans=0;
int mn;
void solve(int place,int tatf,int &n){
	if(place==n+1 && tatf<=mn){
		ans++;
		
//		for(int i=1;i<=place;++i){
//			putchar(' ');
//		}
//		printf("ok!ans=%lld\n",ans);
		return;
	}
	if(tatf>mn)return;
	if(!s[place]){
		
//		for(int i=1;i<=place;++i){
//			putchar(' ');
//		}
//		printf("to *:\n");
		
		solve(place+1,tatf+1,n);
	}
	for(int i=rgo[0];i;i=rgo[i]){
		rgo[lgo[i]]=rgo[i];
		lgo[rgo[i]]=lgo[i];
		if(c[i]>=tatf){
			
//			for(int i=1;i<=place;++i){
//				putchar(' ');
//			}
//			printf("to %d*\n",i);
			
			solve(place+1,tatf+1,n);
		}
		else{
			
//			for(int i=1;i<=place;++i){
//				putchar(' ');
//			}
//			printf("to %d: t=%d\n",i,place+1-tatf);
			
			solve(place+1,tatf,n);
		}
		rgo[lgo[i]]=i;
		lgo[rgo[i]]=i;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int num[2]={0};
	scanf("%d%d",&n,&m);
	mn=n-m;
	{
		char ch=0;
		for(int i=1;i<=n;++i){
			do{
				ch=getchar();
			}while(ch!='1' && ch!='0');
			s[i]=ch-'0';
			num[s[i]]++;
			tat0[i]=num[0];
			if(s[i]==1){
				p1[num[1]]=i;
			}
		}
	}
	if(num[1]<m){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
		lgo[i]=i-1;
		rgo[i-1]=i;
	}
	rgo[n]=0;
	lgo[0]=n;
	long long jc=1;
	for(int i=1;i<=num[0];++i){
		jc=jc*i%mod;
	}
//	printf("[%lld]",jc);
	solve(0,0,n);
	ans%=mod;
//	ans=ans*jc%mod;
	printf("%lld",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/