#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN=1e6+10;
long long n,k,cnt;
long long a[MAXN],s[MAXN];
long long flag[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	memset(flag,0,sizeof(flag));
	for(int i=0;i<n;i++)
	{
		for(int l=1;l<=n;l++)
		{
			if(l+i>n)break;
			int r=l+i;
			bool f=0;
			if((s[r]^s[l-1])==k)
			{
				for(int j=l;j<=r;j++)
				{
					if(flag[j])
					{
						f=1;
						break;
					}
					else flag[j]=1;
				}
				if(f==1)continue;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
