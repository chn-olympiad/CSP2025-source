#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef pair<string,string> p;
string s,t;
p a[N];
int n,q;
int ans=0;
map<int,bool> vis;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	while(q--){
		ans=0;
		cin>>s>>t;
		for(int i=1;i<=n;i++){
			string model=a[i].first;
			int pos=s.find(model);
			string ss=s;
			if(pos!=-1)	ss.replace(pos,a[i].second.size(),a[i].second);
			if(ss==t)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

