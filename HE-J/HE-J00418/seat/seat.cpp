#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,cnt;
long long f[1000][1000],f1[10000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>f1[i];
	}
	sum=f1[1];
	sort(f1+1,f1+m*n+1);
	for(int j=1;j<=m;j++){
		if(j%2==0){
		for(int i=n;i>=1;i--){
		if(f1[cnt]==sum){
				cout<<j<<" "<<i;
				return 0;
			}
			cnt--;
			
		}
		}
		else{
		for(int i=1;i<=n;i++){
		if(f1[cnt]==sum){
				cout<<j<<" "<<i;
				return 0;
			}
			cnt--;
			
		}	
		}
		
	}
	return 0;
} 

