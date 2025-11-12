#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int ans=0;
	int i=0;
	while(i<=n)
	{
		int s=0;
		for(i+=1;i<=n;++i)
		{
			if(a[i]==m)
			{
				++ans;
				break;
			}
			else 
			{
				s=(s^a[i]);
				if(s==m)
				{
					++ans;
					break;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
} 