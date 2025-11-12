#include <bits/stdc++.h>
using namespace std;
int n, q;
map<string, int> mp;
string s[200005];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		string x;
		cin >> x >> s[i];
		mp[x]=i;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string x, y;
		cin >> x >> y;
		for(int len=1;len<=x.size();len++){
			for(int j=0;j<x.size()-len+1;j++){
				string st;
				for(int k=0;k<len;k++){
					st+=x[j+k];
				}
				string xx;
				if(mp[st]!=0){
					for(int k=0;k<x.size();k++){
						if(k<j||k>j+len-1){
							xx+=x[k];
						}else{
							xx+=s[mp[st]];
							k+=len-1;
						}
					}
				}
				if(xx==y){
					ans++;
				}
			}	
		}
		cout << ans << endl;
	}
	return 0;
}
