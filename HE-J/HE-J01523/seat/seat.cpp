#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,cnt,res;
int a[110];
int z[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
		z[i]=a[i];
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		if(a[i]==z[1]){
			res=cnt-i+1;
		}
	}
	if(res%m==0){
		c=res/m;
	}else{
		c=res/m+1;
	}
	if(res%n!=0){
		if(c%2==1){
			r=res%n;
		} else if(c%2==0){
			r=n-res%n+1;
		}
	} 
	if(res%n==0){
		if(c%2==1){
			r=n;
		} else if(c%2==0){
			r=1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
