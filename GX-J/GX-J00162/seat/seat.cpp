#include<bits/stdc++.h>
using namespace std;
long long n,m,p[102],k[11][11],o;
bool qqq(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>p[i];
	o=p[1];
	sort(p+1,p+1+n*m,qqq);
	//for(int i=1;i<=n*m;i++) cout<<p[i]<<endl2 ;
	
	for(long long i=1;i<=n;i++){
		if(i%2==0){
			for(long long j=m;j>=1;j--){
				k[i][j]=p[i];
			}
		}
		else{
			for(long long j=1;j<=m;j++){
				k[i][j]=p[i];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
				if(k[i][j]==o){
					cout<<j<<" "<<i;
					return 0;
				}
		}
	}
}
