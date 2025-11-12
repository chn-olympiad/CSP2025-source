#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,sc,c[110],plus=1,t=1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	sc=c[1];
	sort(c+1,c+(n*m)+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n+1;j+=plus){
			
			if(c[t]==sc){
				if(j=n+1){
					j=n;
				}
				cout<<j<<" "<<i;
				return 0;
			}
			t++;
			if(j==n){
				t++;
			}
		}
		plus-=(plus-plus);
		
	}
}
