/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,q;
struct str{
	string s,s1;
}s[N];
string t,t1;
int cnt;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s>>s[i].s1;
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		cin>>t>>t1;
		for(int i=0;i<t.size();i++){
			for(int j=0;j<t.size();j++){
				if(i+j+1>t.size()){
					break;
				}
				string nr=t.substr(i,j+1);
				cout<<"nr:  "<<nr<<' ';
				for(int k=1;k<=n;k++){
					if(nr==s[k].s){
						if(j+s[k].s1.size()-1>t.size()-s[k].s1.size()){
							break;
						}
						string changestr=t.substr(0,i)+s[k].s1+t.substr(j+s[k].s1.size()-1,t.size()-s[k].s1.size());
						if(changestr==t1){
							cnt++;
						}
					}
				}
			}
			cout<<endl;
		}
		cout<<cnt<<'\n';	
	}
	return 0;
}
