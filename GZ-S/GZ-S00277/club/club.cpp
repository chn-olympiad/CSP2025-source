//GZ-S00277 遵义市南白中学 杨鹏懿 
#include<bits/stdc++.h>
using namespace std;
int t,n,x;
int a[10004][5];
int b[10004];
int m;
void cl(){
	for(int i=1;i<=n+2;i++){
		for(int j=1;j<=3+2;j++){
			a[i][j]=0;
		}
	}
	m=0;
	x=0;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cl();
		cin>>n;
		x=n/2;
		for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}	}
		for(int i=1;i<=n;i++){
			b[i]=a[i][1];
		}
		sort(b,b+1+n);
		for(int i=n;i>x;i--){
			m=m+b[i];
		}	
		cout<<m;
	}
	return 0;
}

