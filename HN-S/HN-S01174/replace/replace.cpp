#include<bits/stdc++.h>
#define pii pair<int,int>
#define vti vector<int>
#define psbk push_back
#define fi first
#define se second

using namespace std;
const int N=200005,INF=0x3f3f3f3f;
int n,q;
string s[N][2],a,b;
string bh(string a,int i,string b){
	return a.substr(0,i)+b+a.substr(i+b.size(),a.size()-(i+b.size())+1); 
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>a>>b;
		int an=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s[i][0].size()-1<a.size();j++){
				if(a.substr(j,s[i][0].size())!=s[i][0]) continue;
				string _a=bh(a,j,s[i][1]);
				if(_a==b){
					an++;
					//cout<<"BB "<<i<<' '<<j<<endl;
				}
			}
		}
		cout<<an<<endl;
	}
	return 0;
}/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
