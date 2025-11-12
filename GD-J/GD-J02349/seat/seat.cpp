#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,b[105][105],k=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	/*
	2 2
	99 100 97 98
	=1 2
	
	2 2
	98 99 100 97
	=2 2
	
	3 3
	94 95 96 97 98 99 100 93 92
	=3 1
	*/
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<endl;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k++;
				if(a[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				k++;
				if(a[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
