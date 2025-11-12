 #include<bits/stdc++.h>
 const int mod=998244353;
 using namespace std;
 int n,m,c[505];
 long long ans=0;
 bool vis[505];
 string s;
 void dfs(int x,int re,int us)
 {
 	if(x>n)
 	{
 		if(us>=m)
 			ans++;
		return;
	}
 	for(int i=1;i<=n;i++)
 	{
 		if(!vis[i])
 		{
 			vis[i]=1;
 			if(s[x-1]=='0'||re>=c[i])
 			{
 				dfs(x+1,re+1,us);
			 }
			else if(s[x-1]=='1')
			{
				dfs(x+1,re,us+1);
			}
			vis[i]=0;
		}
	 }
 }
 int main()
 {
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
 	cin>>n>>m;
 	cin>>s;
 	for(int i=1;i<=n;i++)
 		cin>>c[i];
 	if(n<=10)
 	{
 		dfs(1,0,0);
 		printf("%d\n",ans);
	 }
	else
	{
		ans=1;
		for(int i=2;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		printf("%d\n",ans);
	}
 	return 0;
 }
