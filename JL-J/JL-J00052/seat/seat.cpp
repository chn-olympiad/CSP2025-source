#include<bits/stdc++.h>
using namespace std;
int n,m;
int xr;
int q[105];
int mc=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==1 and m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		cin>>q[i];
		if(i==1){
			xr=q[i];
		}
	}
	sort(q+1,q+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(q[i]==xr){
			mc=n*m-i+1;
		}
	}
	if(mc==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int h=0,l=0;
	for(int i=1;i<=n;i++){
		if(mc>i*m and mc<(i+1)*m){
			l=i;
		}
	}
	if(m%2==0){
		for(int i=0;i<=m;i++){
			if(l*m-i==mc){
				h=i;
			}
		}
	}else{
		for(int i=m;i>=0;i--){
			if(l*m-i==mc){
				h=i;
			}
		}
	}
	cout<<l+1<<" "<<h+1;
	return 0;
}		   

