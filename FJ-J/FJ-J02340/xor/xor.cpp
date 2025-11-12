#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mkp make_pair
#define ft first
#define sc second
int a[500015];
int s[500015];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,sum=0,p=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		sum=sum^a[i];
		int t=sum;
		if(t==k)++cnt,sum=0,p=i;
		else
		{
			for(int r=p+1;r<=i;r++)
			{
				bool flg=0;
				for(int l=p+1;l<=r;l++)
					if((s[r]^s[l-1])==k)
					{
						++cnt;
						flg=1;
						sum=0;
						p=r;
						break;
					}
				if(flg)break;
			}		
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
