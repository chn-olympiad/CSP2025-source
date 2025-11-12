#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool cmp(int a,int b)
{
	if(a!=b) return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid]<=num) r=mid;
		else l=mid+1;
	}
	if(l/m%2==1&&l%m!=0) cout<<l/m+1<<" "<<m-(l%m)+1;
	else if(l/m%2==0&&l%m==0) cout<<l/m<<" "<<1;
	else if(l/m%2==1&&l%m==0) cout<<l/m<<" "<<m;
    else cout<<l/m+1<<" "<<l%m;
	return 0;
}
