#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
unsigned long long ans=0;
int a[5001],n;
void f(int i,int j,int k,int s){
	if(i==j){
		if(k<2)return;
		while(i<=n&&s>a[i]){
			ans++;
			ans%=998244353;
			i++;
		}
		return;
	}
	for(;i<=j;i++)f(i+1,j,k+1,s+a[i]);
	return;
}
int main(){
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)f(1,i,0,0);
	cout << ans;
	return 0; 
}
