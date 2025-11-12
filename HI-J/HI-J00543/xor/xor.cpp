#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m=1,a1[maxn],a2[maxn],k,ans,cnt,x,y;
int f[1005][1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a1[i]);
		a2[i]=a2[i-1]^a1[i];
		if(a1[i]==k)
		{
			f[i][i]=1;
		}
	}
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i<=n-len+1;i++)
		{
			for(int j=i;j<i+len-1;j++)
			{
				ans=a2[i+len-1]^a2[i-1];
				if(ans==k)
				{
					f[i][i+len-1]=1;
				}
				f[i][i+len-1]=max(f[i][i+len-1],f[i][j]+f[j+1][i+len-1]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}

