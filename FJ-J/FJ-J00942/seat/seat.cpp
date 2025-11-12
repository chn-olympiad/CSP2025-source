#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long z=n*m,s=0;
	for(long long i=1;i<=z;i++){
		cin>>a[i];
		if(a[i]>=a[1]){
			s++;
		}
	} 
	for(long long i=1;i<=n;i++){
		if(i%2==1){
			for(long long j=1;j<=m;j++){
				s--;
				if(s==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(long long j=m;j>=1;j--){
				s--;
				if(s==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
