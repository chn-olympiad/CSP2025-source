#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[1000],c,h,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n*m-1;i++){
		cin>>b[i];
	}
	sort(b+1,b+n*m-1+1,cmp);
	for(int i=1;i<=n*m-1;i++){
		if(a>b[i]){
			c=i;
			break;
		}
	}
	l=(c-1)/n+1;
	if(l%2==0){
		if(c%2==0) h=1;
		else h=n+1-(c-c/n*n);
	}
	else{
		if(c%2==0) h=n;
		else h=c-c/n*n;
	}
	cout<<l<<" "<<h;
	return 0;
}
