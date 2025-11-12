#include<bits/stdc++.h>
using namespace std;
int c[1000006];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<n*m;
	return 0;
} 
