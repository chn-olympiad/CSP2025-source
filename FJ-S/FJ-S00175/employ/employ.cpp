#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b=1;
string st;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n-1;i++){
		b*=2;
	}
	cout<<b;
	return 0;
}
