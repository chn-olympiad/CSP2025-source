#include<bits/stdc++.h>

using namespace std;

int n,q;
string s1,s2;
string x,y;
map<string,string> mp;

string f(string u,int beg,int end){
	string ans="";
	for(int i = beg; i <= end; i ++ ){
		ans += u[i];
	}
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; i ++ ){
		cin>>s1>>s2;
		mp[s1] = s2;
	}
	while(q -- ){
		cin>>x>>y;
		int ans = 0;
		for(int i = 0; i < x.size(); i ++ ){
			if(i != 0 && x[i-1] != y[i-1])break;
			for(int j = x.size()-1; j >= 0; j -- ){
				if(j != x.size()-1 && x[j+1] != y[j+1])break;
//				cout<<i<<" "<<j<<" |";
//				cout<<f(x,i,j)<<"| |"<<f(y,i,j)<<"| |"<<mp[f(x,i,j)]; 
				if(mp[f(x,i,j)] == f(y,i,j)){
					ans ++ ;
//					cout<<1;
				}
//				cout<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
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
