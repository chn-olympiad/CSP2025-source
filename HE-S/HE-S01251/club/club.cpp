#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,m;
int a[100000][3];
int smtx(int w,int zong,int r,int t,int u)
{
	if(w>=n)
	{
		return zong;
	}
	if(r>=m)
	{
		if(t>=m)
		{
			return smtx(w+1,zong+a[w][3],r,t,u+1);
		}
		else{
			if(n>=m)
			{
				return smtx(w+1,zong+a[w][2],r,t+1,u);
			}
			else{
				return max(smtx(w+1,zong+a[w][2],r,t+1,u),smtx(w+1,zong+a[w][3],r,t,u+1));
			}
		}
	}else{
		if(t>=m)
		{
			if(u>=m)
			{
				return smtx(w+1,zong+a[w][1],r+1,t,u);
			}
			else
			{
				return max(smtx(w+1,zong+a[w][1],r+1,t,u),smtx(w+1,zong+a[w][3],r,t,u+1));
			}
		}
		else{
			if(u>=m)
			{
				return max(smtx(w+1,zong+a[w][1],r+1,t,u),smtx(w+1,zong+a[w][2],r,t+1,u));
			}
			else
			{
				return max(smtx(w+1,zong+a[w][1],r+1,t,u),max(smtx(w+1,zong+a[w][2],r,t+1,u),smtx(w+1,zong+a[w][3],r,t,u+1)));
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		m=n/2;
		cout<<smtx(-1,0,0,0,0)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
