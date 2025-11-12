#include<bits/stdc++.h>
using namespace std;
int a[102];
int c[12][12];
int ans;
int r,l;
int ny[3]{1,-1};
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		r=a[1];
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			l=i;
		}
		//n*m+1-l
		int k=n*m+1-l;
		if(k==1)
		{
		cout<<1<<' '<<1;
		break;
		}
		if(k==m*n)
		{
			cout<<n<<' '<<m;
			break;
		}
		int lie;
		if(n*m+1-l<=n)
		lie=1;
		else if((n*m+1-l)/m%1==0&&(n*m+1-l)>n)
		{
			lie=(n*m+1-l)/m;
		}
		int hang1=(n*m+1-l)%n;
			int hang2=m+1-(n*m+1-l)%n;
		if(n*m+1-l<=n)
		{
			cout<<1<<' '<<n*m+1-l;
			break;
		}
		else if(n*m+1-l>n)
		{
			if(m%2!=0)
			{
			cout<<lie<<' '<<hang1;
			break;
			}
			else if(m%2==0)
			{
			cout<<lie<<' '<<hang2;
			break;
		
			}
		}
		
	}
	
return 0;
}
