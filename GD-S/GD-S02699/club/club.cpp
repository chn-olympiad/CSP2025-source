#include<bits/stdc++.h>
using namespace std;
int t,n,dp[10005][20005];
struct g{
	int a,b,c,cnt,cdt;
}x[150005];
bool cmp(g x,g y){
	if(x.cnt!=y.cnt)	return x.cnt>y.cnt;
	return x.a>y.a;
}
bool cmp2(g x,g y){
	if(x.a!=y.a)	return x.a>y.a;
	return x.b>y.b;
}
bool cmp3(g x,g y){
	if(x.cdt!=y.cdt)	return x.cdt>y.cdt;
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		int mx=0,bj=0;
		memset(x,0,sizeof(x));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&x[i].a,&x[i].b,&x[i].c);
			x[i].cnt=x[i].b-x[i].c,x[i].cdt=x[i].a-x[i].b;
			if(x[i].b!=0)	bj=1;
		}
		if(n<=20000){
			sort(x+1,x+1+n,cmp);
			for(int i=0;i<=n/2;i++){
				int s=0;
				for(int j=1;j<=n;j++){
					if(i!=0)	dp[i][j]=dp[i-1][j-1]+x[j].a;
					if(x[j].b>x[j].c){
						if(s>=(n/2))	dp[i][j]=max(dp[i][j],dp[i][j-1]+x[j].c);
						else	dp[i][j]=max(dp[i][j],dp[i][j-1]+x[j].b),s++;
					}
					else{
						if((j-i-s)>=(n/2))	dp[i][j]=max(dp[i][j],dp[i][j-1]+x[j].b),s++;
						else dp[i][j]=max(dp[i][j],dp[i][j-1]+x[j].c);
					}
				}
				mx=max(mx,dp[i][n]);
			}
			printf("%d",mx);
		}
		else if(!bj){
			sort(x+1,x+1+n,cmp2);
			int s=0;
			for(int i=1;i<=n/2;i++)
				s+=x[i].a;
			for(int i=n/2+1;i<=n;i++)
				s+=x[i].c;
			cout<<s;
		}
		else{
			int s=0;
			sort(x+1,x+1+n,cmp3);
			for(int i=1;i<=n/2;i++)
				s+=x[i].a;
			for(int i=n/2+1;i<=n;i++)
				s+=x[i].b;
			cout<<s;
		}
	}
	return 0;
}

