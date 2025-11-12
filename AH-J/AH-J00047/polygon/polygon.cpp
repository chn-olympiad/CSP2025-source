#include<bits/stdc++.h>
using namespace std;
int n,j,i,o,a[5005],f=0;;
long long h=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0){
		for(i=3;i<=n;i++){
			int y=1;
			for(j=1;j<=i;j++){
				y=y*(n-j+1);
			}
			h=(h+y)%998244353;
		}
		cout<<h;
		return 0;
	}
	if(n<=3){
		if(2*max(a[1],max(a[2],a[3]))<a[1]+a[2]+a[3]){
			h++;
		}
		cout<<h%998244353;
		return 0;
	}
	for(i=3;i<=n;i++){
		for(j=1;j<=n-i+1;j++){
			int m=0,y=0;
			for(o=j;o<=j+i-1;o++){
				m=max(m,a[o]);
				y=y+a[o];
			}
			if(y>m*2){
				h++;
			}
		}
	}
	cout<<h%998244353;
	return 0;
}
