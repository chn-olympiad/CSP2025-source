#include<bits/stdc++.h>
using namespace std;
int a[1011];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=n*m;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+p+1,greater<int>());
	int s=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			int j=1;
			for(;j<=n;j++){
				if(a[s]==k){
					cout<<i<<' '<<j;
					return 0;
				}
				s++;
			}
		}
		else{
			int j=n;
			for(;j>=1;j--){
				if(a[s]==k){
					cout<<i<<' '<<j;
					return 0;
				}
				s++;
			}
		}
	}
	return 0;
} 
