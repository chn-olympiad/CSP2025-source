#include <bits/stdc++.h>
using namespace std;

int b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
	}
	int bi=b[1];
	int ww;
	sort(b+1,b+k+1);
	for(int i=1;i<=k;i++)
	{
		if(b[i]==bi)
		{
			ww=i;
			break;
		}
	}
	int w=k-ww+1;
	int d=w/n;
	int f=w%n;
	if(d==0&&f>0) cout<<1<<" "<<f;
	if(d==1&&f==0) cout<<1<<" "<<n;
	if(d==1&&f>0) cout<<d+1<<" "<<n-f+1;
	if(d>1&&d%2==0&&f>0) cout<<d+1<<" "<<f;
	if(d>1&&d%2==0&&f==0) cout<<d<<" "<<1;
	if(d>1&&d%2==1&&f>0) cout<<d+1<<" "<<n-f+1;
	if(d>1&&d%2==1&&f==0) cout<<d<<" "<<n;
	
	
	return 0;
}
