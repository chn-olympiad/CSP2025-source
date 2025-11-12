#include<bits/stdc++.h> 
using namespace std;
long long n,m;
long long a[15][15],b[105],c[105];
bool cmp(long long x,long long y){
	return c[x]>c[y];
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	for(int i=1;i<=100;++i)b[i]=i;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>c[i];
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;++i)cout<<c[b[i]]<<' '<<b[i]<<' '<<i<<'\n';
	for(int i=1;i<=n*m;++i){
		long long x=(i+n-1)/n;
		long long y;
		if(x&1){
			y=(i-1)%n+1; 
		}
		else{
			y=n-(i-1)%n;
		}
		
		a[x][y]=c[b[i]];
		if(b[i]==1){
			 cout<<x<<' '<<y<<'\n';
		} 
		
	}
}
