#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a[105],th;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==a1){
			th=i;
		}
	}
	int l=ceil(double(th*1.0/n));
	cout<<l<<" ";
	if(l%2==1){
		cout<<th-n*(l-1);
	}
	else{
		cout<<n-(th-n*(l-1))+1;
	}
	return 0;
}
