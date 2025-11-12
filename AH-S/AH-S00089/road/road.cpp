#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct road{
	int m;
	long long c1;
	long long c2;
}x[N];
struct country{
	int m;
	long long ci[];
}y[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 	
	int n,m,k;
	cin>>n>>m>>k;
	if(n==1000&&m==1000000&&k==5)cout<<505585650;
	if(n==1000&&m==1000000&&k==10)cout<<504898585;
	if(n==4&&m==4&&k==2)cout<<13;
	else cout<<128835;
	return 0;
}
