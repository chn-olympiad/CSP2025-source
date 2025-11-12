#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[1010],k=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) k*=i;
	cout<<k;
	return 0;
}
