#include<bits/stdc++.h>
using namespace std;
int n,q,l,t,w,p,u,ans;
char a[1001][3][2005],x[2600],y[2600];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		t=0;
		w=0;
		cin>>x>>y;
		l=strlen(x);
		for(int j=0;j<l;j++)
		{
			if(y[j]!=x[j])
			{
				t=j;
				break;
			}
		}
		for(int j=l-1;j>=0;j--)
		{
			if(y[j]!=x[j])
			{
				w=j;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(strlen(a[i][1])>=w-t+1)
			{
				for(int j=0;j<strlen(a[i][1]);j++)
				{
					if(a[i][1][j]!=a[i][2][j])
					{
						p=j;
						break;
					}
				}
				u=1;
				for(int j=p;j<strlen(a[i][1]);j++)
				{
					if(a[i][1][j]!=x[t+j-p]||a[i][2][j]!=y[t+j-p])
					{
						u=0;
						break;
					}
				}
				ans+=u;
			}
		}
		cout<<ans<<endl;
	}
}
























