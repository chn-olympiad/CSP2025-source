#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,p;//r cj
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//jideigaizushu
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r)p=i;
	}
	if(p<=m){
		cout<<1<<" "<<p;
		return 0;
	}
	int t=0;
	if(p%m==0){
		t=p/m;
	}
	else{
		t=p/m+1;
	}
	if(t%2==0){
		cout<<t<<" "<<m*t-p+1;
	}
	else{
		cout<<t<<" "<<p-m*(t-1);
	}
	return 0;
}
