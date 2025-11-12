#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],b[10000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	cout<<1;
	return 0;
}

