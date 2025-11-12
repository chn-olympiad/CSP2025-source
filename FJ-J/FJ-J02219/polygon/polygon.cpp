#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N],f[N],m=-1;
int C(x,y){
	ans=1;
	for(int i=x;i<=y;i++){
		ans*=x;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]-a[2]<a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(m==1){
		int c=0,tmp;
		for(int j=1;j<=n;j++){
			c+=C(j,n);
		}
		cout<<c;
		return 0;
	}
}