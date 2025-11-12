#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a=1;
	for(int i=2;i<=n;i++){
		a*=i;
	}
	cout<<a;
	return 0;
}