#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,q;
string s[N][2],t1,t2;

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	
	while(q--){
		cin>>t1>>t2;
		cout<<0<<"\n";
	}
	
	return 0;
}
