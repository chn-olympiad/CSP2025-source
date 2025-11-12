#include<bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp(const long long &x,long long &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>m>>n;
	long long r;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	long long w;
	for(long long i=1;i<=n*m;i++){
		if(a[i]==r) w=i;
	}
	for(long long i=1;i<=n;i++){
		if(i%2==1){
			for(long long j=m;j>=1;j--){
				w--;
				if(w==0){
				cout<<i<<' '<<m-j+1;
				break;
				}
			}
		}
		else{
			for(long long j=1;j<=m;j++){
				w--;
				if(w==0){
				cout<<i<<' '<<m-j+1;
				break;
				}
			}
		}
	}
	return 0;
}
