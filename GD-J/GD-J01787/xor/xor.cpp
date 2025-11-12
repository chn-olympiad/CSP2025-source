#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	char a[500005],b[500005];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&a[i]);
		b[i]=int(b[i-1]^(a[i]-'0'));
	}
	int i=0,j=1;
	int ans=0;
	while(i<=n&&j<=n)
	{
		for(int x=j;x>i;x--)
		{
			if(int(b[j]^b[x-1])==k)
			{
				i=j;
				ans++;
				break;
			}
		}
		j++;
	}
	printf("%d",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
