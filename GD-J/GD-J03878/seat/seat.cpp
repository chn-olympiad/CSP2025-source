#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	//int b[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int x=a[0][0];
	if(n<=1&&m<=1) cout<<1<<" "<<1;
	else if(m=1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-j;j++){
			if(a[j][0]<a[j+1][0]) swap(a[j][0],a[j+1][0]);
		}
		}
		for(int i=0;i<n;i++){
			if(x==a[i][0]) cout<<i+1;
		}
	}
	else if(n=1){
		for(int i=0;i<m;i++){
			for(int j=0;j<m-i-j;j++){
			if(a[0][j]<a[0][j+1]) swap(a[0][j],a[0][j+1]);
		}
		}
		for(int i=0;i<m;i++){
			if(x==a[0][i]) cout<<i+1;
		}
	}
	else if(n==2&&m==2){
		int a1=2,a2=1;
		int d[4];
		d[0]=a[0][0];
		d[1]=a[0][1];
		d[2]=a[1][0];
		d[3]=a[1][1];
		for(int i=0;i<4;i++){
		for(int j=0;j<4-i-1;j++){
		if(d[j]<d[j+1]) swap(d[j],d[j+1]);
	}
	}
	if(x==d[0]) {
		cout<<a2;
		cout<<" ";
		cout<<a2;
	}
	if(x==d[1]) {
	cout<<a2;
	cout<<" ";
	cout<<a1;
	}
	if(x==d[2]) {
	cout<<a1;
	cout<<" ";
	cout<<a1;
	}
	if(x==d[3]) {
	cout<<a1;
	cout<<" ";
	cout<<a2;
	}
	}	
}
