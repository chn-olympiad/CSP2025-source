#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,b[105],num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1){
			x=b[i];
		}
	}
	sort(b+1,b+n*m+1);
	for(int i=0;i<n*m-1;i++){
		a[i+1]=b[n*m-i];
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				num++;
				if(a[num]==x){
					cout<<i<<" "<<j;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				num++;
				if(a[num]==x){
					cout<<i<<" "<<j;
				}
			}
		}
	}
} 
