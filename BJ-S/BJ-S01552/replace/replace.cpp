#include <iostream>
#include <string>
#define fi first
#define se second
using namespace std;
int n,q;
const int N=200010;
pair<string,string>s[N];
string a,b;
void xyb(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
int main(){
	xyb();
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i].fi>>s[i].se;
	while(q--){
		cin>>a>>b;
		int cnt=0;
		for(int i=1;i<=n;i++){
			int p=a.find(s[i].fi);
			if(p!=(int)string::npos){
				if(a.substr(0,p)+s[i].se+a.substr(p+s[i].fi.size())==b)cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
