#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10005];
bool cmp(int a,int b)
{
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%lld",&a[i]);
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=0;
	for(int i=1;i<=n*m;i++)if(a[i]==R)x=i;
	int se=0;
	for(int i=1;i<=m;i++)
	{
		se+=n;
		if(se<x)continue;
//		cout<<x<<endl;
//		cout<<se<<endl;
		se-=n;
		int A=0,B=i;
		if(i&1)A=x-se;
		else A=x-se,A=n-A+1;
		printf("%lld %lld",B,A);
		break;
	}
	return 0; 
}/*
2 2
99 100 97 98

4 2
1 4 5 6 7 8 9 100
*/
