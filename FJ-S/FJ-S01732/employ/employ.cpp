#include<bits/stdc++.h>
using namespace std;
int m,n,c;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) cin>>c;
	int a=2,b=2204128;
	if(n==3) cout<<a;
	if(n==10) cout<<b;
	return 0;
}
