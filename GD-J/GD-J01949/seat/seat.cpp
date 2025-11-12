#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define sf scanf
#define pf printf
int n,m,a[105],sum;
int main(){
	fin("seat.in");
	fout("seat.out");
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		sf("%d",&a[i]);
		if(a[i]>a[1])sum++;
	}
	int x=1,y=1,d=1;
	for(int i=1;i<=sum;i++){
		x+=d;
		if(x>n)x=n,y++,d=-d;
		if(x<=0)x=1,y++,d=-d;
	}
	cout<<y<<" "<<x;
	return 0;
}

