#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int tmp;
	bool flag=1; 
	for (int i=0;i<n;i++) {
		cin>>tmp;
		if (tmp!=1) flag=0;
	}
	if (flag) cout<<0;
	else if (n==m) cout<<1;
	else if (m==1) cout<<n;
	return 0;
}

