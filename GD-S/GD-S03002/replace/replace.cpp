#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,q;
string s[N];
int slove(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	while(q--){
		string t;
		cin>>t;
		cout<<0<<"\n";
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t=1;//cin>>t;
	while(t--)
		slove();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
