#include<bits/stdc++.h>
using namespace std;
int n,m,ans,num;
string s;
int c[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) num++;
	}
	bool an=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') an=0;
		
	}
	if(an){
		if(n-num<m){
			cout<<0;return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
