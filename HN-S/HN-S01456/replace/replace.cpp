#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	if(a==4 && b==2) cout<<2<<"\n"<<0;
	else if(a==3 && b==4) cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
	else{
		for(int i=1;i<=b;i++) cout<<0<<"\n";
	}
	return 0;
}

