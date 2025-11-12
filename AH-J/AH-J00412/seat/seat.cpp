#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+10;
struct student
{
	long long s,id;
}a[N];
long long n,m,k,c,r;
bool cmp(student u,student v)
{
	return u.s>v.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	k=n*m;
	for(long long i=1;i<=k;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+k+1,cmp);
	for(long long i=1;i<=k;i++){
		if(a[i].id==1){
			c=(i+n-1)/n;
			if((i-1)/n%2==0)r=(i-1)%n+1;
			else r=n-(i-1)%n;
			break;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
