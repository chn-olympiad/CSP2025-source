#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000,MOD=0,inf=0x3f3f3f3f;
int a[N];
bool cmp(int a,int b) {return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==p) {p=i;break;}
	int r=(p-1)/n,g=p-r*n;
	if(r&1) g=n-g+1;
	cout<<r+1<<" "<<g<<endl;
	return 0;
}
