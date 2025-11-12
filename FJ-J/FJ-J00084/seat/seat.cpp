#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[2005][2005],s,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	t=n*m;
	for(long long i=1;i<=n;i++){
		if(i%2==0){
			for(long long j=m;j>=1;j--){
				if(a[t]==s){
					cout<<i<<' '<<j;
					return 0;
				}
			t--;
			}
		}
		if(i%2==1){
			for(long long j=1;j<=m;j++){
				if(a[t]==s){
					cout<<i<<' '<<j;
					return 0;
				}
				t--;
			}
		}
	}
	return 0;
} 
