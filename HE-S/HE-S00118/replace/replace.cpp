#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2*1e5+5;
string s[N][3];
int n,q;
string ZC(int x,int y,string a){
	string b;
	for(int i=x;i<=y;i++) b+=a[i];
	return b;
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<+n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		string a,b,c;
		cin>>a>>b;
		
	}
	
	return 0;
}
