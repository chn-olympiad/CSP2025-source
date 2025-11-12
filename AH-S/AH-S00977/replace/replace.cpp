#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+20;
ll n,q;
map<string,string>m;
string xyz[N];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string st1,st2;
		cin>>st1>>st2;
		m[st1]=st2;
		xyz[i]=st1;
	}
	while(q--){
		cin>>s1>>s2;
		int ans=0;
		if(s1!=s2){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			string c1=s1,c2=s2;
			if(s1.find(xyz[i])!=string::npos&&s2.find(m[xyz[i]])!=string::npos){
				long long b=s1.find(xyz[i])+xyz[i].size();
				c1.erase(0,b);c2.erase(0,b);
				if(c1==c2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
