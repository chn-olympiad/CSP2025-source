#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int cj=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				int t;
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}	
	}
	int sum;
	for(int i=0;i<=n*m;i++){
		if(a[i]==cj)sum=i+1;
	}
	int c=0,r=0;
	while(sum>0){
		for(int i=0;i<m;i++){
			c=i;
			if(i%2==0){
				for(int j=0;j<n;j++){
					r=j;
					sum--;
					if(sum<=0)break;
				}
			}
			else if(i%2==1){
				for(int l=n-1;l>=0;l--){
					r=l;
					sum--;
					if(sum<=0)break;
				}
			}
			if(sum<=0)break;
		}
	}
	cout<<c+1<<" "<<r+1;
	return 0;
}
