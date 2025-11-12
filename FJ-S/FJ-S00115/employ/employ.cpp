#include<bits/stdc++.h>
using namespace std;

int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int p=0;
	int n,m;
	cin>>n>>m;
	int q=0;
	int c[n+1];
	string a[n+1];
	for(int i=1;i<=n+1;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n+1;i++){
		if(a[i]==0){
			p++;
		}else{
			continue;
		}
	}
	cout<<p%998244353;
	return 0;
}
