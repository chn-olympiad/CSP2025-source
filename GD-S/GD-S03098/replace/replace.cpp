#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100005][3];
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
//		cout<<s[i][1]<<" "<<s[i][2]<<'\n';
	}
	while(q--){
		string from,to;cin>>from>>to;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(from.find(s[i][1])!=-1){
				int to1=from.find(s[i][1]);
//				cout<<s[i][1]<<" "<<s[i][2]<<'\n';
//				cout<<s[i][1].size()<<"\n";
//				cout<<to1<<" "<<to1+s[i][1].size()-2<<'\n';
				int tolen=to1+s[i][1].size()-1;
				string str="",str1="";
				for(int j=to1-1;j<=tolen;++j)
					str+=s[i][2][j],
					str1+=to[j-to1+1];
				if(str==str1)cnt++;
//					cout<<j<<" "<<(char)to[j]<<"\n";
//				cout<<str<<'\n';
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
