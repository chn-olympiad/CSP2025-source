#include<bits/stdc++.h>
using namespace std;
int n,m,b[121],t,k=1,e;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1) t=b[i];
		else if(b[i]>t) e++;
	}
	bool f=1;
	e++;
	for(int i=1;i<=n;i++)
	{
		if(f==1)
		{
			for(int j=1;j<=m;j++)
			{
				if(k==e) cout<<i<<" "<<j<<endl; 
				k++;
			}
			f=0;
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				if(k==e) cout<<i<<" "<<j<<endl; 
				k++;
			}
			f=1;
		}
	}
	return 0;	
}
