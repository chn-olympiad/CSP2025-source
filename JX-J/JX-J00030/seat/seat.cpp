#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[100001]={},w;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long q=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			w=i;
			break;
		}
	}
	w=n*m-w+1;
	long long s=w/(2*m),d=w%(2*m);
	if(w%(2*m)<=m){
		cout<<1+2*s<<" "<<w%(2*m);
	}else{
		cout<<2+2*s<<" "<<2*m-d+1;
	}
	return 0;
}
