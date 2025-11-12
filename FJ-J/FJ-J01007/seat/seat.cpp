#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m,idx;
	while(l<=r)
	{
		int mid=(r-l)/2+l;
		if(a[mid]<k)
		{
			r=mid-1;
		}
		else if(a[mid]>k)
		{
			l=mid+1;
		}
		else
		{
			idx=mid;
			break;
		}
	}
	int c=(idx%n!=0)?idx/n+1:idx/n;
	int rr=(c%2==0)?n-idx%n+1:(idx%n==0)?n:idx%n;
	cout<<c<<" "<<rr;
	return 0; 
}
