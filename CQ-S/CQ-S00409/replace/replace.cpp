#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define mod
using namespace std;
const int N=200005;
int n,q;
string s1[N],s2[N],tx[N],ty[N];
unordered_map<string,vector<string> > mp;
unordered_map<int,bool> sz;
vector<string> flg;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
//		if(!mp[s1[i]].size()) mp[s1[i]]=flg;
		mp[s1[i]].push_back(s2[i]);
		sz[s1[i].size()]=1;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		tx[0]=t1[0];
		for(int i=1;i<t1.size();i++) tx[i]=tx[i-1]+t1[i];
		for(int i=t1.size()-1;i>=0;i--) ty[i]=ty[i+1]+t1[i];
		for(int i=0;i<t1.size();i++) reverse(ty[i].begin(),ty[i].end());
		int cnt=0;
		for(int i=0;i<t1.size();i++){
			string y="";
			for(int j=i;j<t1.size();j++){
				y+=t1[j];
				if(!sz[y.size()]) continue;
				if(mp[y].size()){
					for(int k=0;k<mp[y].size();k++){
						string p,q=mp[y][k];
						if(i==0) p=q+ty[j+1];
						else p=tx[i-1]+q+ty[j+1];
//						cout<<i<<" "<<j<<" "<<p<<endl;
						if(p==t2) cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
l*l

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/

