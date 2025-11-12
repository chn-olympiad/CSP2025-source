#include<bits/stdc++.h>
using namespace std;
int a[1008],temp;
bool cmp(int w,int z)
{
	return w>z;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		temp=a[0];
	sort(a,a+n*m,cmp);
			if(a[i]==temp)
		{
			double t=i;
			int w;
			double z=ceil((t+1)/m);
			cout<<z<<" ";
			w=int(t)%m;
			if(int(z)%2==1)
			{
				cout<<w+1;
			}
			else
			{
				cout<<n-w;
			}
		}
	}
	return 0;
	}
