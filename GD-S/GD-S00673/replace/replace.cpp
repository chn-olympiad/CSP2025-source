#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,Q,ans = 0;
string s1[N],s2[N],t1,t2;
bool check( string s , int l,int r,string t){
	if( r-l+1 != t.length() ) return false;
	for(int i = 0,j = l;i < t.length();i++,j++)
		if( t[i] != s[j] ) return false;
	return true;	
}
void dfs(string s){
	if( s == t2){
		++ans;
		return;
	}
	for(int l = 0;l < s.length();++l){
		for(int r = l;r < s.length();r++){
			for(int i = 1;i <= n;i++){
				if( check(s , l , r , s1[i] ) ){
					string k = "";
					for(int j = 0;j < l;j++) k += s[j];
					k += s2[i];
					for(int j = r+1;j < s.length();j++) k += s[j];
					dfs( k ); 
				}
			}
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++)
		cin >> s1[i] >> s2[i];
	while( Q-- ){
		cin >> t1 >> t2;
		ans = 0;
		dfs( t1 );
		cout << ans <<"\n";
	}	
	return 0;
}

