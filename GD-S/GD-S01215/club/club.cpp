#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int n,t,i,j,a[N][5],s,l[5],ma;
void dfs(int k)
{
	int i;
	for(i=1;i<=3;i++)
	{
		if(l[i]<n/2)
		{
			l[i]++;
			s+=a[k][i];
			if(k==n)
			{
				ma=max(ma,s);
			}
			else
			{
				dfs(k+1);
			}
			l[i]--;
			s-=a[k][i];
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		l[1]=0;
		l[2]=0;
		l[3]=0;
		s=0;
		ma=INT_MIN;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1);
		cout<<ma<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
