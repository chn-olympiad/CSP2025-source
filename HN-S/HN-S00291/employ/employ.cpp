#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int t=m%998;
	t%=244;
	t%=353;
	cout<<t<<enl;
	return 0;
}
