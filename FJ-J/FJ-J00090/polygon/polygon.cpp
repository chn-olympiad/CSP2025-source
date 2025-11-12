#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
int c[10000],top=0,ans=0;
int maxn,all;
void find(int x,int start)
{
	for(int i=start+1;i<=n;i++)
	{
		top+=1;
		c[top]=a[i];
		if(x==1)
		{
			maxn=0,all=0;
			for(int i=1;i<=top;i++)
			{
				maxn=max(c[i],maxn);
				all+=c[i]; 
			} 
			if(all>maxn*2)
				ans++;
		}
		if(x>1)
			find(x-1,i);
		top--;
	} 
	return ;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3)
	{
		cout<<"0";return 0;
	}
	for(int i=3;i<=n;i++)find(i,0);
	cout<<ans;
	return 0;
}
