#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int k,i,j,sum;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n;i++){
		
		if(i%2){
			for(j=1;j<=m;j++){
				sum++;
				if(a[sum]==k){
					cout<<i<<" "<<j;
					return 0;
				} 
			}	
		}else{
			for(j=m;j>=1;j--){
				sum++;
				if(a[sum]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	return 0;
}

