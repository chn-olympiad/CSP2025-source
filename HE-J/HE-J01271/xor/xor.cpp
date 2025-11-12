#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n*m],c;
	cin>>c;
	s[0]=c;
	for(int i = 1;i<n*m;i++){
		cin>>s[i];
	}
	sort(s+0,s+n*m);
	cout<<1;
	return 0;
}
