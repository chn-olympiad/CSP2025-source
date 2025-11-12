#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,s,t,k;
void g(int b){
	if(b>n) return;
	if(b>=3&&sum>a[b]*2){
		t++;
	}
	for(int i=b+1;i<=n;i++){
		sum+=a[i];
		g(i);
		sum-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++) cin >>a[i];
	sort(a,a+n+1);
	g(0);
	cout <<t;
	
	return 0;
}
