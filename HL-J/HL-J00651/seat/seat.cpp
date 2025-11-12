#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm,x,c=0,mn=0;
	bool a=1;
	int arr[101],brr[11][11];
	cin>>n>>m;
	nm=m*n;
	while(nm--){
		cin>>x;
		if(c==0){
			arr[c]=x*10+1;
			c++;
		}else{
			arr[c]=x*10;
			c++;
		}
	}
	sort(arr,arr+c);
	for(int i=0;i<n;i++){
		if(a){
			for(int j=0;j<m;j++){
				c--;
				brr[j][i]=arr[c];
			}
		}else{
			for(int j=m-1;j>=0;j--){
				c--;
				brr[j][i]=arr[c];
			}
		}
		a=!a;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(brr[i][j]%10==1){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	return 0;
}
