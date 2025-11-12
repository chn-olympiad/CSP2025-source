#include<bits/stdc++.h> 
using namespace std;
int n,m,a[505],b[505],c[505],mod=998244353;
string x;
int jch(int z){
	int num=1;
	for(int i=2;i<=z;i++){
		num=num*i%mod;
	}
	return num;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n;i++){
		a[i]=x[i-1]-'0';
		b[i]=b[i-1]+(1-a[i]);
	}
	if(b[n]==0){
		cout<<jch(n);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	int ans=jch(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(c[i]<b[j]){
				ans=ans/n*j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
