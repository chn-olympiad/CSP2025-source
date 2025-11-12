#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0) r=a[i];
	}
	sort(a,a+n*m,cmp);
	int id;
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			id=i;
		}
	}
	int l=id/n+1;
	int h=id%n+1;
	if(l%2==1){
		cout<<l<<' '<<h;
	}
	else{
		cout<<l<<' '<<n-h+1;
	}
	return 0;
}