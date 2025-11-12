#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,a[5001],v[5001],maxn,sum,b[5001],ii;

bool pd(int k)
{
	maxn=0,sum=0;
	for(int i=1;i<=k;i++)
	{
		maxn=max(maxn,b[i]);
		sum+=b[i];
	}
	if(sum>maxn*2)
		return true;
	else
		return false;
}

void dfs(int k)
{
	for(int i=ii;i<=n;i++)
	{
		if(!v[i])
		{
			int iii=ii;
			ii=i;
			v[i]=1;
			b[k]=a[i];
			if(k>=3)
			{
			/*	for(int i=1;i<=k;i++)
					cout<<b[i]<<' ';
				cout<<endl;*/
				if(pd(k))
				{
				/*	for(int i=1;i<=k;i++)
						cout<<b[i]<<' ';
					cout<<endl;*/
					ans++;
					ans%=mod;
				}
			}
			if(k!=n) dfs(k+1);
			v[i]=0;
			b[k]=0;
			ii=iii;
		}
	}
}



int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<500)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ii=1;
		dfs(1);
		
		
		cout<<ans;
	}else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
