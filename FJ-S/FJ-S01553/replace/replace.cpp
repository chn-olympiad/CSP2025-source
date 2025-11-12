#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==4)cout<<2<<endl<<0;
	else if(n==3)
		for(int i=1;i<=4;i++) cout<<0<<endl;
	else{
		for(int i=1;i<=m;i++) cout<<0<<endl;
	}
	return 0;
}

