#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	int pppy=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			pppy=i;
			break;
		}
	}
	int cyj=ceil(1.0*pppy/m);
	if(cyj%2==0){
		if(pppy%m==0)cout<<cyj<<" "<<1;
		else cout<<cyj<<" "<<m-pppy%m+1;
	}
	else{
		if(pppy%m==0)cout<<cyj<<" "<<m;
		else cout<<cyj<<" "<<pppy%m; 
	}
	return 0;
}
