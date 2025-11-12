#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
int ans;
string dict[N][2];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>dict[i][0]>>dict[i][1];
	}
	int cnt;
	while(q--){
		cnt=0;
		string qwq,awa;
		cin>>qwq>>awa;
		for(int i=1;i<=n;i++){
			int pos=0;
			while(1){
				pos=qwq.find(dict[i][0],pos);
				if(pos==string::npos)break;
				if(qwq.substr(0,pos)+dict[i][1]+qwq.substr(pos+dict[i][0].size())==awa){
					cnt++;
				}
				pos++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}