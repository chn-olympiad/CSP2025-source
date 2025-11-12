#include<bits/stdc++.h>
using namespace std;
long long int n,m,a,k;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a!=0)k++;
	}
	cout<<(k*(k-1))/2%998244353;
	return 0;
}