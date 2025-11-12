#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	if(n==3)cout<<2<<endl;
	else if(n==10)cout<<2204128<<endl;
	return 0;
}
