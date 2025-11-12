#include<bits/stdc++.h>
using namespace std;
int a[1001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,mi,sum,h,l;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	mi=a[0];
	sort(a,a+n*m,cmp);	
	for(int i=0;i<n*m;i++){
		if(a[i]==mi){
			sum=i+1;
			break;
		}
	}
	if(sum<=n)
	{
		cout<<1<<" "<<sum;
	}
	else {
		if(sum%n!=0) l=sum/n+1;
		else l=sum/n;
		if(l%2!=0) h=sum%n;
		else h=n-sum%n+1;cout<<l<<" "<<h;
	}
	
 } 
