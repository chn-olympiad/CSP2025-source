#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1005];
int sum;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			sum++;
		} 
	}
	sum++; 
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				sum--;
				if(sum==0){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				sum--;
				if(sum==0){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
} 
