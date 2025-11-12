#include<bits/stdc++.h>
using namespace std;
int b[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,d=1;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>b[i];
	}
	c=b[1];
	sort(b+1,b+1+(n*m));
	if(m%2!=0){
		d=1;
	for(int i=m;i>0;i--){
		d=n*d-n;
		for(int j=n;j>0;j--){
			d+=j;
			if(b[d]==c){
				if(i%2!=0){
					cout<<m-i+1<<" "<<n+1-j;
					return 0;
				}else{
				 cout<<m-i+1<<" "<<j;
				 return 0;
				}
			}
		}
	}
}else for(int i=m;i>0;i--){
	d=n*d-n;
		for(int j=1;j<=n;j++){
			d+=j;
			if(b[d]==c){
				if(i%2==0){
					cout<<m-i+1<<" "<<j;
					return 0;
				}else {
				cout<<m-i+1<<" "<<n+1-j;
				return 0;
				}
			}
		}
	}
	return 0;
}
