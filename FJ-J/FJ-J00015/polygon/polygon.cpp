#include<bits/stdc++.h>
using namespace std;
int n,s,ans,maxx=-1,k;
int a[5005];
void f(int x){
	for(int i=x;i<=n;i++){
		maxx = -1;
		s = 0;
		for(int j=1;j<=i;j++){
			s+=a[j];
			maxx = max(a[j],maxx);
		}
		if(s > maxx*2){
			ans++;
		} 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f(i);
	}
	cout<<ans%998244353;
	return 0;
}
