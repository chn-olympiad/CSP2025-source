#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
int bc;
int pm;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	bc=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
		if(a[i]==bc){
			pm=i;
			break;
		}
	}
//	cout<<endl;
	int c,r;
	c=(pm+n-1)/n;
	r=pm%m;
	if(r==0) r=n;
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
