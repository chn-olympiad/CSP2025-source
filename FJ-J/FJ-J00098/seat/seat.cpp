#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	int wz;
	for(int i=1;i<=n*m;i++)
		if(a[i]==tmp){
			wz=i;
			break;	
		}
	int c,r;
	if(wz%n==0){
		c=wz/n;
	}
	else{
		c=wz/n+1;
	}
	if(c%2==1){
		if(wz%n==0)
			r=n;
		else
			r=wz%n;
	}
	else
		r=n-wz%n+1;
	cout<<c<<' '<<r<<endl;
	return 0;
}
