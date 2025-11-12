#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,s;
string s1,s2,a[200005],b[200005];
void dfs(int h,string s1,string s2){
	if(s1==s2){
		s++;
		return;
	}
	if(h)return;
	string x="",y="";
	for(int i=1;i<=n;i++){
		for(int j=0;j+signed(a[i].size())-1<=n;j++){
			if(s1.substr(j,a[i].size())==a[i])x=s1.substr(0,j),y=s1.substr(j+a[i].size()),dfs(1,x+b[i]+y,s2);
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(k--){
		s=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue; 
		}
		dfs(0,s1,s2);
		cout<<s<<"\n";
	}
	return 0;
}
