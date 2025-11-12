#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m,a[120],aa,aaa,ii,jj;
	cin>>n>>m;
	cin>>aa;
	a[1]=aa;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aa){
			aaa=i;
			break;
		}
	}
	ii=ceil((aaa+0.0)/n);
	jj=aaa%n;
	if(jj==0){
		jj=n;
	}
	if(ii%2==0){
		jj=n-jj+1;
	}
	cout<<ii<<" "<<jj;
	return 0;
}
