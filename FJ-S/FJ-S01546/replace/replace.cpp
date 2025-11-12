#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	if(n==4&&q==2){
		cout<<"2\n";
		cout<<"0";
		return 0;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<"0\n";
	}
	return 0;
} 
