#include<bits/stdc++.h>
using namespace std;
int m,n,x,sum,c,r;
int a[1100];
bool flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=m*n;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+sum);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[sum]==x){
					flag=1;
					c=i;
					r=j;
					break;
				}
				sum--;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[sum]==x){
					flag=1;
					c=i;
					r=j;
					break;
				}
				sum--;
			}
		}
		if(flag==1){
			cout<<c<<" "<<r;
			break;
		}
	}
	return 0;
} 
