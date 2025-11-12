#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,x;
	cin>>n>>m>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==r) x=i;
	if(x%n==0) cout<<x/n<<" ";
	else cout<<x/n+1<<" ";
	if(x%(2*n)>n) cout<<n+1-x%n;
	else if(x%(2*n)==0) cout<<1;
	else if(x%n==0) cout<<n;
	else cout<<x%n;
	return 0;
}
