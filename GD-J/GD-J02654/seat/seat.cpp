#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	feropen("seat.in","r",stdin);
	feropen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	int b;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			b=i;
			break;
		}
	}
	if(b%n==0){
		int o=b/n;
		if(o%2==0)cout<<o<<' '<<1;
		else cout<<o<<' '<<n;
	}
	else{
		int o=b/n+1;
		if(o%2==0)cout<<o<<' '<<n-b%n+1;
		else cout<<o<<' '<<b%n;
	}
	return 0;
}
