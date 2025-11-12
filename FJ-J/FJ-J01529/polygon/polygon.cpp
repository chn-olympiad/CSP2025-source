#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5005];
void f(int xi, int nn, int num){
	if(nn > n) return;
	if(nn >= 3){
		if(num > a[xi]*2){
			ans++;
			ans %= 998244353;
		}
	}
	for(int i=xi+1; i <= n; i++){
		f(i,nn+1,num+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i <= n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i <= n; i++) f(i,1,a[i]);
	cout<<ans;
	return 0;
}
