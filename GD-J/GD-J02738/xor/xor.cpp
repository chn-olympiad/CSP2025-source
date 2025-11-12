#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ans;
int a[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	a[0]=1;
	cin>>n>>m;
	if(!m){
		for(int i=1;i<=n;i++){
			cin>>x;
			if(!x) ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		y^=x;
		a[y]++;
		if(a[y^m]){
			memset(a,0,sizeof(a));
			a[0]=1;
			ans++;
			y=0;
		}
	}
	cout<<ans;
	return 0;
} 
