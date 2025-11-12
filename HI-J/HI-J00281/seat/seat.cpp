#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000000]={},b,c,r;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
		b=a[0];
	}	
	for(int i=0;i<m*n;i++){
		if(a[i]==b){
			if(i%m==0){
				c=i/m;
				if(c%2==0){
					r=n-i%m;
				}
				else{
					r=i%m;
				}
			}
			else{
				c=i/m+1;
				if(c%2==0){
					r=n-i%m;
				}
				else{
					r=i%m;
				}
			}
		}
	}
	cout<<c+1<<" "<<r;
	
	return 0;
}
