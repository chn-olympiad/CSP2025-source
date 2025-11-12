#include<bits/stdc++.h>
using namespace std;

long long t,n,a[100005][4],ma,nc,s[4];
void dfs(long long ii,long long cou)//s1-->>shendu1
{
	if(ii>n)
	{
		ma=max(ma,cou);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(s[i]<n/2)
		{
			s[i]++;
			dfs(ii+1,cou+a[ii][i]);
			s[i]--;
		}
		
	}
	
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
		while(t--)
	{
		memset(a,0,sizeof(a));
		ma=0;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		memset(s,0,sizeof(s));
		dfs(0,0);
		cout<<ma<<endl;
	}
	return 0;
}
