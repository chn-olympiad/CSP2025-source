#include <bits/stdc++.h>
using namespace std;
long long n,m,aa[1000],a[100][100],s,ss=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=n*m;i++)cin>>aa[i];
	ss=aa[1];
	sort(aa,aa+n*m+1);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int k=m;k>=1;k--){
				a[i][k]=aa[s];
				s--;
			}
		}else{
			for(int k=1;k<=m;k++){
				a[i][k]=aa[s];
				s--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==ss){
				cout<<i<<" "<<j;
				return 0; 
			}
		}
	}
	return 0;
} 
