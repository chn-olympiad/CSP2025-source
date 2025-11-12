#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,m,b[2]={-1,1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int j;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int sum=a[0],z=n*m-1;
	sort(a,a+m*n);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			j=n;
		}else{
			j=1;
		}
		for(;j<=n&&j>=1;j+=b[i%2]){
			if(a[z]==sum){
				cout<<i<<" "<<j;
				return 0;
			}
			z--;
		}
	}
	return 0;
} 
