#include<bits/stdc++.h>
using namespace std;

int n,ans=0;
int gun[5000+10];
bool pan[5000+10];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>gun[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		pan[i]=true;
		for(int j=1;j<=n;j++)
		{
			while(pan[j]==true)
				j++;
			
			pan[j]=true;
			
			for(int z=1;z<=n;z++)
			{
				while(pan[z]==true)
					z++;
				if(gun[i]+gun[j]+gun[z]>2*max(max(gun[i],gun[j]),max(gun[z],gun[j])))
					ans++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			pan[i]=false;
		}
	}
	
	cout<<ans;
}
