#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s[20][20],c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a,a+n*m+1);
	int h=1,l=1;
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=n*m;i>=1;i--){
		if(h!=n){
			for(int j=1;j<=n;j++){
				s[j][l]=a[i];
				if(h!=n) h++;
				i--;
			}
		}
		if(h==n){
			l++;
			for(int j=n;j>=1;j--){
				s[j][l]=a[i];
				if(h!=1) h--;
				i--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==c) cout<<j<<" "<<i;
		}
	}
	return 0;
}