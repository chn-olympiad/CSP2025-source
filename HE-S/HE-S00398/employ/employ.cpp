#include<bits/stdc++.h>
using namespace std;
long long  n,m=1,a[1000],b[1000];
string s;
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
		for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<+n;i++){
		m*=n;
	}
	cout<<m;
	return 0;
}
