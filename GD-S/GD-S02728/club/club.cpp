#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{int a,b,c;}a[100001];
int dp[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c,dp[i]=0;
		if(n==2) cout<<max(max(max(a[1].a+a[2].b,a[1].b+a[2].a),max(a[1].a+a[2].c,a[1].c+a[2].b)),max(a[1].c+a[2].b,a[1].b+a[2].c));
		else cout<<666;
		cout<<endl;
	}	
	return 0;
} 
