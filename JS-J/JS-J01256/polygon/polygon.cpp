#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void f(int p,int k,int sum){
	if(k == 1) return ;
	for(int i = 1;i<k;i++){
		if(sum+a[i] > a[p]){
			ans++;
		}
		f(p,i,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1 ;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n == 3 && a[1]+a[2]>a[3]){
		cout<<1;
		return 0;
	}
	else if(n == 3 && a[1]+a[2]<=a[3]){
		cout<<0;
		return 0;
	}
	for(int i = 3;i<=n;i++){
		f(i,i,0);
	}
	cout<<ans;
	return 0;
}

