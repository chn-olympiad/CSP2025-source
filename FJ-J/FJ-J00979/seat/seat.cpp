#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q=n*m;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+q+1,cmp);
	int y=0;
	for(int i=1;i<=q;i++){
		if(a[i]==x){
			y=i;
			break;
		}
	}
	int c,r;
	c=ceil(y*1.0/n);
	if(c%2){
		r=0+y%n;
		if(!r)r=n;
	}else{
		r=n-y%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
