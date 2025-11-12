#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
int num;
int sum;
int a[100100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>=k){
			num++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(num==sum){
					cout<<i<<" "<<j;
					return 0;
				}sum++;
			}
		}else {
			for(int j=n;j>=1;j--){
				if(num==sum){
					cout<<i<<" "<<j;
					return 0;
				}sum++;
			}
		}
	}
	return 0;
}
