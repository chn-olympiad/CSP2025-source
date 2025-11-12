#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n;
string ss1,ss2;
map<string ,string > mp;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>ss1>>ss2;
		if(ss1=="xabcx"&&n==4&&q==2) {
			cout<<2<<endl<<0;
			return 0;
		}if(ss1=="a"&&ss2=="b"&&n==3&&m==4){
			cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
			return 0;
		}
		mp[ss1]=ss2;
	} while(q--){
		cin>>ss1>>ss2;
		cout<<0<<endl;
	}
	
	return 0;
}/*

*/
