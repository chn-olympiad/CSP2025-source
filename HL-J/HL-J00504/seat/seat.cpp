#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,r=1,k=0;
	cin>>n>>m;
	int a[10001]={0};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i+1]>a[1]){
			if(k==0){
				r++;
			}
			if(r==n+1&&m!=c){
				c++;
				k=1;
			}
			if(k==1){
				r--;
				if(r==1&&m!=c){
					k=2;
					c++;
				}	
			}
			if(k==2){
				r++;
				if(r==n+1&&m!=c){
					c++;
					k==1;
				}
			}
		}
		else{
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}