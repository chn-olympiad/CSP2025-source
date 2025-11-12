#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,aaa,a[100010];
inline int up(int a,int b)
{
	return a/b+(bool)(a%b);
}
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>aaa;
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a+1,a+n*m,cmp);
	
//	for(int i=1;i<n*m;i++) cout<<a[i]<<' ';
//	cout<<endl;
	
	int l=1,r=n*m-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>aaa) l=mid+1;
		else r=mid;
//		cout<<l<<' '<<r<<endl;
	}
//	cout<<l<<' '<<r<<endl;
//	l -> 第几个 

//	l/n -> 第几列
//  n-l%n -> 第几行(如果为奇则减，偶则增)
/*

up(l,n) 第几列 
*/
	cout<<up(l,n)<<' '<<(up(l,n)%2?(l%n?l%n:n):n-l%n+1);
//	cout<<l%n;
	return 0;
} 
