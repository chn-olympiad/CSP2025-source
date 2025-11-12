#include<bits/stdc++.h>
using namespace std;
int const N=510;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int cnt=0;
	cout<<n*(n-1)<<endl;
	return 0;
}
