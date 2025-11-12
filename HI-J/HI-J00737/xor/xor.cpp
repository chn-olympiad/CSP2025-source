#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[200010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k=0)
	{
		printf("%d",n);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]^a[i]==k) ans++;
		else if(a[i]^a[i+1]==k&&i+1<=n) i++,ans++;
		else if(a[i]^a[i]^a[i+2]==k&&i+2<=n) i+=2,ans++;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
