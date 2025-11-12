#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
bool pd(string s,string t,string x,string y){
	int o=s.find(x),q=t.find(y);
	while(o!=q){
		if(o>q)q=t.find(y,q+1);
		else o=s.find(x,o+1);
	}
	if(o==-1)return 0;
	s.erase(o,x.size());
	t.erase(q,y.size());
	if(s==t){
		return 1;
	}
	return 0;
}

int n,q;
string s[N],t[N];
signed main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
cin>>n>>q;
for(int i=1;i<=n;i++){
	cin>>s[i]>>t[i];
}
string x,y;
for(int i=1;i<=q;i++){
	cin>>x>>y;
	int sum=0,xx=x.size(),yy=y.size();
	for(int j=1;j<=n;j++){
		if(s[j].size()<xx||xx!=yy)continue;
		if(s[j].find(x)!=-1&&pd(s[j],t[j],x,y))sum++;
	}
	cout<<sum<<"\n";
}
return 0;
}
