#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans;
long long ll;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char p[n+1];
	int c[n+1];
	for(int i=0;i<=n;i++){
		cin>>p[i];
	}
	for(int i=0;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<=n;i++){
		if(p[i]=='0'){
			++x;
		}
	}
	if(n-x < m){
		cout<<0;
	}else{
		ans=(2*n*n-4*n)/3;
		cout<<ans;
	}
	return 0;
}