#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		cnt+=c;
	}
	cout<<cnt;
	return 0;
} 
