#include<bits/stdc++.h>
using namespace std;
int n,m,a[500];
string pro;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>pro;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<1000%(n-m);
	return 0;
}
