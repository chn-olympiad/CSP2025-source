#include <bits/stdc++.h>
using namespace std;
int n,m,a,h,l,v[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int x=1;x<=n*m;x++){
		cin>>v[x];
	}
	a=v[1];
	sort(v+1,v+n*m+1,cmp);
	for(int x=1;x<=n*m;x++){
		if(v[x]==a){
			a=x;
		}
	}
	l=(a-1)/n+1;
	if(l%2==1){
		h=(a-1)%n+1;
	}else{
		h=n-((a-1)%n+1)+1;
	}
	cout<<l<<' '<<h;
	return 0;
}
