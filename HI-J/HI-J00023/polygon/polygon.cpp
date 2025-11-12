#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans=0;
int n;
ll a[5005];
bool comp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,comp);
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(a[i]*2<a[j]+a[j-i]+a[i]&&a[i]!=a[j]&&a[i]!=a[j-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
