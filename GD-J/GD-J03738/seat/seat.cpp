#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],h=2,l=1,t=1,u=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	sort(a+2,a+n*m+1,cmp);
	if(a[1]>a[2])
	{
		cout<<"1 1";
		return 0;
	}
	if(a[1]<a[n*m])
	{
		cout<<n<<" "<<m;
		return 0;
	}
	for(int i=2;i<n*m;i++)
	{
		if(a[1]<a[i]&&a[1]>a[i+1])
		{
			cout<<l<<" "<<h;
			return 0;
		}
		if(t==1)
		{
			if(h<n)h++;
			else 
			{
				l++;
				t=2;
			}
		}
		else if(t==2)
		{
			if(h>1)h--;
			else 
			{
				l++;
				t=1;
			}
		}
	}
	return 0;
}
