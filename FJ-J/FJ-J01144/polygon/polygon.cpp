#include<iostream>
#include<cstring>
using namespace std;
const int MOD=998244353;
int lowbit(int x){
	return x&(-x);
}
int aaa(int x){
	int ans=0;
	while(x!=0){
		x=x-lowbit(x);
		ans++;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(n>22){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*2%MOD; 
		}
		ans=ans-1-n-(n*(n-1)/2);
		if(ans<0)
			ans=(ans+MOD)%MOD;
		else
			ans=ans%MOD;
		cout<<ans;
		return 0; 
	}
	for(int i=0;i<(1<<n);i++){
		bool vis[25];
		memset(vis,0,sizeof(vis));
		int k=i;
		for(int j=n;j>=0;j--){
			if(k>=(1<<j)){
				vis[j+1]=1;
				k-=(1<<j);
			}
		}
		if(aaa(i)<3)
			continue;
		int sum=0,maxx=-1;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum+=a[i];
				maxx=max(maxx,a[i]);
			}
		}
		if(maxx*2<sum)
			ans++; 
	}
	cout<<ans;
	return 0;
}
/*
RRRRRRR        PPPPPPP
RRRRRRRRR      PPPPPPPPP
RR     RR      PP	  PP	++	   ++	
RR     RR	   PP     PP	++     ++
RRRRRRRRR	   PPPPPPPPP  ++++++ ++++++
RRRRRRRRR	   PPPPPPPPP  ++++++ ++++++
RRRR 		   PP			++     ++
RRRRR		   PP			++     ++
RR RRR		   PP	
RR  RRR		   PP
RR   RRR	   PP
RR    RRR 	   PP 
*/ 
