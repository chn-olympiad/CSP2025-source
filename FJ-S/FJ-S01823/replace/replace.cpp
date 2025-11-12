//rp++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,set<string>> tran;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	while(n--){
		string a,b;
		cin>>a>>b;
		tran[a].insert(b);
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int cnt1=0,cnt2=a.size()-1;
		long long ans=0;
		while(a[cnt1]==b[cnt1]) cnt1++;
		while(a[cnt2]==b[cnt2]) cnt2--;
		for(int i=0;i<=cnt1;i++){
			string p1=a.substr(i,cnt2-i);
			string p2=b.substr(i,cnt2-i);
			for(int j=cnt2;j<a.size();j++){
				p1+=a.substr(j,1);
				p2+=b.substr(j,1);
				if(tran[p1].find(p2)!=tran[p1].end()) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
