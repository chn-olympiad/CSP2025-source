#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
string s[N],t[N],a[N],b[N];
void calc(string s,string t,string a,string b){
	int p=-114;
	while(1){
		if(p==-114)p=a.find(s);
		else p=a.find(s,p+1);
		if(p==-1)break;
		if(a.substr(0,p)+t+a.substr(p+s.size())==b)ans++;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i]>>t[i];
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++){
		ans=0;
		for(int j=1;j<=n;j++)calc(s[j],t[j],a[i],b[i]);
		cout<<ans<<endl;
	}
}