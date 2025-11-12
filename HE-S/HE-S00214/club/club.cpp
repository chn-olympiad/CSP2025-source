#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n[t];
	for(int i=0;i<t;i++)
	{
		cin>>n[i];
		int s[n[i]+1][4];
		for(int j=1;j<=n[i];j++)
		{
			for(int y=1;y<=3;y++)
			{
				cin>>s[j][y];
			}
		}
		int du[4]={0};
		int ren[4]={0};
		for(int j=1;j<=n[i];j++)
		{
			int u=0,r=0;
			for(int y=1;y<=3;y++)
			{
				if(s[j][y]>u)
				{
					u=s[j][y];
					r=y;
				}
			}
			if(ren[r]+1<=n[i]/2)
			{
			du[r]+=u;
			ren[r]++;
		}
		else{
			int p=0;
			for(int y=1;y<=3;y++)
			{
				if(s[j][y]<u&&s[j][i]>=p)
				{
					p=s[j][y];
					r=y;
				}
			}if(ren[r]+1<=n[i]/2)
			{
			du[r]+=u;
			ren[r]++;
		}
		else{
			for(int y=1;y<=3;y++)
			{
				if(s[j][y]<u&&s[j][i]<=p)
				{
					p=s[j][y];
					r=y;
				}
			}
			if(ren[r]+1<=n[i]/2)
			{
			du[r]+=u;
			ren[r]++;
		}
		}
		}
	}
	int sum=0;
	for(int i=1;i<=3;i++) sum+=du[i];
	cout<<sum<<endl;
} 
fclose(stdin);
fclose(stdout);
return 0;
}
