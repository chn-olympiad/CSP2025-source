#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],s[101],c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(i==1) c=1,r=1;
	else if(i==n) c=1,r=n;
	else if(i==m*n) c=m,r=n;
	while(n){
		if(i%n==0){
			if(i/2n==0) c=i/n,r=1;
			else c=i/n,r=n;
		}
		else c=i/n+1,r=(i/n)*n+i%n;
	}
	cout<<a[1];
	return 0; 
}
