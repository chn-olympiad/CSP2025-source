#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e2+5;

int n,m;
int r,c;

int a[N];

signed main(){
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;for(int i=1;i<=n*m;++i)cin>>a[i];
	int tmp=a[1];sort(a+1,a+n*m+1);
	tmp=n*m-(lower_bound(a+1,a+n*m+1,tmp)-a-1);
	if(tmp%n)c=tmp/n+1;
	else c=tmp/n;
	if(c&1){
		if(c>1)r=tmp-(c-1)*n;
		else r=tmp;
	}else r=n-(tmp-(c-1)*n)+1;
	return cout<<c<<" "<<r<<"\n",0;
}