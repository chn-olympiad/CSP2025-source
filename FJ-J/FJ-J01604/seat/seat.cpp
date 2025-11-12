#include <bits/stdc++.h>
using namespace std;
int n,m,tmp,a1,x[500],y[500],xx=1,yy=1,s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	for(int i=1;i<n*m;i++){
		cin>>tmp;
		if(tmp>a1) s++;
	}
	if(m==1){
		cout<<s<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) x[xx++]=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) y[yy++]=j;
		for(int j=n;j>=1;j--)y[yy++]=j;
	}
	cout<<x[s]<<" "<<y[s];
	return 0;
}
