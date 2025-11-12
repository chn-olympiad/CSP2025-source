#include<bits/stdc++.h>
using namespace std;
int A(int m,int n){
	if(m==n) return 1;
	int a=1,b=1;
	for(int i=m;i>m-n;i--) a*=i;
	for(int i=2;i<=n;i++) b*=i;
	return a/b;
}
int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[5005]={};
	int n; cin >> n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1) f=0;
	} 
	if(n==3&&a[1]+a[2]+a[3]>max({a[1],a[2],a[3]})*2) cout << 1;
	else if(n==3) cout << 0;
	else{		
		int cnt=0;
		for(int i=3;i<=n;i++){
			cnt+=A(n,i);
			cout << cnt << " ";
			cnt%=mod;
		} 
		if(f){
			cout << cnt;
		} 
		else{
			cout << cnt/2-666;
		}
	} 
	return 0;
} 
