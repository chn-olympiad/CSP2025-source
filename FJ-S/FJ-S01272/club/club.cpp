#include<bits/stdc++.h>
using namespace std;

int n,t,dp[4][100000],c1,c2,c3;

struct great{
	int c1,c2,c3,all;
}a[100000];

bool cmp(great a,great b){
	return a.all>b.all;
}

void jian(int i)
{
	bool f1=false,f2=false,f3=false;
	if(dp[1][i]==dp[2][i]){
		if(c1>c2){c1--;f1=true;}
		else if(c2>c1){c2--;f2=true;};
	}
    if(dp[1][i]==dp[3][i]){
		if(c1>c3&&f1==false)c1--;
		else if(c3>c1){c3--;f3=true;};
	}
	if(dp[3][i]==dp[2][i]){
		if(c3>c2&&f3==false)c3--;
		else if(c2>c3&&f2==false)c2--;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		c1=c2=c3=0;
		cin>>n;
			for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			a[i].all=a[i].c1+a[i].c2+a[i].c3;
		}
			sort(a+1,a+n+1,cmp);
		    for(int i=1;i<=n;i++){
		    	if(c1<n/2)dp[1][i]=max(dp[1][i-1],max(dp[3][i-1],dp[2][i-1]))+a[i].c1;
		    	if(c2<n/2)dp[2][i]=max(dp[1][i-1],max(dp[3][i-1],dp[2][i-1]))+a[i].c2;
		    	if(c3<n/2)dp[3][i]=max(dp[1][i-1],max(dp[3][i-1],dp[2][i-1]))+a[i].c3;
		    	int ans=max(max(dp[1][i],dp[2][i]),dp[3][i]);
		    	if(dp[1][i]==ans)c1++;
		    	if(dp[2][i]==ans)c2++;
		    	if(dp[3][i]==ans)c3++;
		    	jian(i);
	        }
	cout<<max(dp[1][n],max(dp[2][n],dp[3][n]))<<"\n";
}
	return 0;
}
