#include<bits/stdc++.h>
using namespace std;

int m,n,x,sum;
int a[150];
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
		if(i==0){
			x=a[i];
		}
		else if(x<a[i]){
			sum++;
		}
	}
	
	sort(a,a+m*n);
	sum++;
	
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				sum--;
				if(sum==0){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				sum--;
				if(sum==0){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
