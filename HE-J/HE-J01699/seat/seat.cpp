#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+5]={0};
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int c=1,r=1;
	int b=a[0];
	sort(a,a+n*m+1);
	if(a[0]==b){
		cout<<c<<" "<<r;
		return 0;
	}
	if(b>=a[n*m+1]){
		cout<<"1"<<" "<<"1";
		return 0;
	}
	for(int i=n*m;i>0;i--){
		if(b<a[i]){
			if(r<n or r<1){
				if(c%2==0){
					r--;
						
				}else{
					r++;
				}
			}else{
				c++;
			}
		}
	}
	if(c>m){
		c=m;
	}
	cout<<c<<" "<<r;
	return 0;
}
