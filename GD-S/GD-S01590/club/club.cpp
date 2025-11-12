 #include<bits/stdc++.h>
 using namespace std;
 int t,n,ans,a[100005][5];
 void dfs(int x,int aa,int bb,int cc,int sum)
 {
 	if(x>n)
 	{
 		if(sum>ans)
 			ans=sum;
 		return;
	 }
 	for(int i=1;i<=3;i++)
 	{
 		if(i==1&&aa<n/2)
 		{
 			dfs(x+1,aa+1,bb,cc,sum+a[x][i]);
		 }
 		if(i==2&&bb<n/2)
 		{
 			dfs(x+1,aa,bb+1,cc,sum+a[x][i]);
		 }
 		if(i==3&&cc<n/2)
 		{
 			dfs(x+1,aa,bb,cc+1,sum+a[x][i]);
		 }
	 }
 }
 int main()
 {
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	scanf("%d",&t);
 	while(t--)
 	{
 		ans=0;
 		scanf("%d",&n);
 		for(int i=1;i<=n;i++)
 		{
 			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
 	return 0;
 }
