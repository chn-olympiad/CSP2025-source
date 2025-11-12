#include <bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,m,ij=1,bb,ansx,ansy;
long long a[1010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i=i+1){
		cin>>a[i];
		if(i==1){
			bb=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i=i+1){
		if(i%2!=0){
			for(int j=1;j<=n;j=j+1){
				if(a[ij]==bb){
					ansx=i;
					ansy=j;
				}
				ij=ij+1;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j=j-1){
				if(a[ij]==bb){
					ansx=i;
					ansy=j;
				}
				ij=ij+1;
			}
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
