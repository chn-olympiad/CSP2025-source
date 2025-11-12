#include<bits/stdc++.h>
using namespace std;
int n,a[10001],q=0;
void go(int i,int s,int z,int l,int da){
	if(i==s+1){
		if(z>2*da){
			q++;
			q%=998244353;
		}
		return;
	}
	for(int j=l+1;j<=n;j++){
		go(i+1,s,z+a[j],j,max(a[j],da));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		go(1,i,0,0,-1);
	}
	cout<<q;
	return 0;
}/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
