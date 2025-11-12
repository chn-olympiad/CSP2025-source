#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int id=1;
	cin>>n>>m;
	int a[1000];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int zhu=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==zhu){
			id=i;
			break;
		}
	}
	int l=0;
	if(id==n) l=1;
	else if(id%n==0){
		l=id/n;
	}
	else {
		l=id/n+1;
	}
	int hang=0;
	if(l%2==1){
		if(id%n==0) hang=n;
		else hang=id%n;
	}
	else if(l%2==0){
		if(id%n==0) hang=1;
		else hang=n-(id%n)+1;		
	}
	cout<<l<<" "<<hang;
	return 0;
}
