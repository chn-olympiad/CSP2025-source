#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	bool flag=true;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=1)flag=false;
	}
	if(flag){
		int ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0')ans++;
			else break;
		}
		cout<<min(ans,m);
	}
	if(m==1){
		cout<<1;
	}
	return 0;
}
