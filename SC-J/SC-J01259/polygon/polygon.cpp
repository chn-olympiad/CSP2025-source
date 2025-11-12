#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int f[10000];
int s;
bool v;
ll c(int m,int n){
	ll c=1;
	for(int i=m;i>=m-n;i--){
		c*=i;
	}
	for(int i=n;i>=1;i--){
		c/=i;
	}
	return c;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		if(v==true){
			if(f[i]==0){
				v=false;
			}
		}
	}
	if(n==3){
		if(f[1]+f[2]+f[3]>max({f[1],f[2],f[3]})){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(v){
		for(int i=3;i<=n;i++){
			s+=c(n,i);
		}
		cout<<s;
		return 0;
	}
}