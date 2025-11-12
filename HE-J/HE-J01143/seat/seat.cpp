#include <bits/stdc++.h>
using namespace std;
int a[101];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,d;
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		if(i==1){
			cin>>s;
			a[1]=s;
		}
		else{
			cin>>a[i];
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]==s){
			d=i;
			break;
		}
	}
	//cout<<d;
	int r,l;
	r=ceil(1.0*d/n);
	for(int i=1;i<=n;i++){
		if(d<n) break;
		d=d-n;
	}
	l=d;
	if(l==0 && r%2==1){
		l=n;
	}else if(l==0 && r%2==0){
		l=1;
	}
	if(r%2==1){
		cout<<r<<' '<<l;
	}else{
		cout<<r<<' '<<n-l+1;
	}
	return 0;
}
