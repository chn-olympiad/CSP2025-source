#include<bits/stdc++.h>
using namespace std;
string s[2000005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
	}
	int ans;
	for(int i=1;i<=4;i++){
		cout<<ans<<" ";
	}
	
}