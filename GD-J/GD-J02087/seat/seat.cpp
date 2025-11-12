#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
		cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m);
	for(long long i=1,j=n*m;i<j;i++,j--)
		swap(a[i],a[j]);
	for(long long i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			if(((i+m-1)/m)%2==1)
			{
				cout<<(i+m-1)/m<<" "<<(i-1)%m+1;
				break;
			}
			else
			{
				cout<<(i+m-1)/m<<" "<<m-((i-1)%m);
				break;
			}
		}
	}
	return 0;
}
