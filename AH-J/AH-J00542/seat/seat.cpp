#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	int nb=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			nb=i;
			break;
		}
	}
	int b,c;
	b=ceil((double)nb/n);
	c=nb%m;
	if(b%2==0){
		if(c==0){
			cout<<b<<" "<<1;
		}
		else{
			cout<<b<<" "<<n-c+1;
		}
	}
	else{
		if(c==0){
			cout<<b<<" "<<n;
		}
		else{
			cout<<b<<" "<<c;
		}
	}
	return 0;
}
