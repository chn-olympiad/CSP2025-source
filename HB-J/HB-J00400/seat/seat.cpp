#include <bits/stdc++.h>
using namespace std;
int a[140];
bool cmp(const int& a,const int& b){
	return a<b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) x=a[i]; 
	}
	sort(a+1,a+n*m+1,cmp);
	int idx;
	for(idx=1;idx<=n*m;idx++){
		if(a[idx]==x) break;
	}
	int l=((idx+n-1)/n)%2,h=0;
	h=idx%n;
	if(h==0) h=n;
	if(l==0){
		cout<<l<<n-h+1;
	}
	else cout<<l<<h;
}
