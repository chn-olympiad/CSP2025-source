#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,P=998244353;
long long n,m,x,y,c[N],t,a[N],b[N],h,k[N],g,j,mi=1e8;
string s;
struct no{
	long long a,b,c;
}d[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>y;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>m>>y>>x>>t>>g;
		j=m+y+x+t+g;
		if(j<mi)mi=j;
	}
	cout<<mi;
	return 0;
}
