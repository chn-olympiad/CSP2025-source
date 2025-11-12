#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],cnt=0;
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]=='1')cnt++;
	}
	cout<<cnt;
	return 0;
}
