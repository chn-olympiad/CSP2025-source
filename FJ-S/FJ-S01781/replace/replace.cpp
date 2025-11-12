#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+5;
int n,q;
pair<string,string> p[N];
ll cnt=0;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>p[i].first>>p[i].second;
	}
	while(q--) {
		cnt=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {
			cout<<0<<endl;
			continue;
		}
		for(int i=1; i<=n; i++) {
			string Find=p[i].first;
//			cout<<endl<<"now:find:   "<<Find<<endl<<"pos:";
			int nowpos=0;
			while(t1.find(Find,nowpos)<=t1.size()-1&&t1.find(Find,nowpos)>=0) {
				int pos=t1.find(Find,nowpos);
//				cout<<pos<<" ";
				nowpos=pos+1;
				string Uses="";
				Uses=Uses+t1;
//				cout<<Uses<<".replace("<<pos<<","<<pos+p[i].first.size()-1<<","<<p[i].second<<")"<<endl;
				for(int j=pos; j<=pos+Find.size()-1; j++) {
					Uses[j]=p[i].second[j-pos];
				}
//				cout<<"now's Uses:   "<<Uses<<endl;
				if(Uses==t2)cnt++;
			}
//			cout<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
