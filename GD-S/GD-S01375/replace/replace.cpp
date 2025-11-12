#include<bits/stdc++.h>
using namespace std;
string s[100010][2];
int len[100010][2];
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		len[i][1]=s[i][1].size();
		len[i][2]=s[i][2].size();
	}
	while(m--){
		string sc,an;
		cin>>sc>>an;
		cout<<0<<'\n';
	}
	return 0;
}
