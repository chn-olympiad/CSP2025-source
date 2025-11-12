#include<bits/stdc++.h>
using namespace std;
int n,m,a[505000],s[505000];
int lst,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)  
	{
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=lst;j<i;j++)
		{
			if((s[i]^s[j])==m) 
			{
				ans++;
			//	cout<<j+1<<" "<<i<<" "<<(s[i]^s[j])<<endl;
				lst=i;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
