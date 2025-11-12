#include<bits/stdc++.h>
using namespace std;
struct p{
	long long num;
	long long bi;
}a[110],st[15][15];
long long n,m;
bool cmp(p x,p y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long total=n*m;
	for(long long i=1;i<=total;i++){
		cin>>a[i].num;
		a[i].bi=i;
	}
	sort(a+1,a+1+total,cmp);
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++){
			if(i%2==1){
				st[j][i]=a[n*(i-1)+j];
			}
			else{
				st[j][i]=a[n*(i-1)+n-j+1];
			}
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			if(st[j][i].bi==1)
			cout<<i<<' '<<j;
		}
	}
	return 0;
} 
