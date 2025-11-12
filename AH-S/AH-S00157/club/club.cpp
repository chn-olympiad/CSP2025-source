#include <bits/stdc++.h>
using namespace std;
int const N=100005;
int a[N][5],n,l; 
//priority_queue<int,vector<int>,greater<int> > dp;
int jd=INT_MIN;
void dfs(int t1,int b1,int b2,int b3,int ans,int l)
{
	//cout<<l<<endl;
	if(b1>l/2||b2>l/2||b3>l/2) return ;
	if(b1+b2+b3==l+1) return ;
	jd=max(jd,ans);
	b1++;
	dfs(t1+1,b1,b2,b3,ans+a[t1][1],l);
	b1--,b2++;
	dfs(t1+1,b1,b2,b3,ans+a[t1][2],l);
	b2--,b3++;
	dfs(t1+1,b1,b2,b3,ans+a[t1][3],l);
	b3--;
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		jd=INT_MIN;
		int n;
		cin>>n;
		l=n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
		    {
				if(a[i][1]<a[j][1]||(a[i][1]==a[j][1]&&a[i][2]<a[j][2]))
				{
					swap(a[j][1],a[i][1]);
					swap(a[j][2],a[i][2]);
					swap(a[j][3],a[i][3]);
				}
				//for(int i=1;i<=n;i++) cout<<a[i][1]<<" "<< a[i][2]<<" "<<a[i][3]<<endl;
			//cout<<endl;
					
		    }
		//for(int i=1;i<=n;i++) cout<<a[i][1]<<" "<< a[i][2]<<" "<<a[i][3]<<endl;
		dfs(1,0,0,0,0,n);
		cout<<jd<<endl;
	}
	return 0;
}
