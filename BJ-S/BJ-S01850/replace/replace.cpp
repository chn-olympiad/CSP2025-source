// 谐音替换
/*
 
 暴力分 
  
 
 * */
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, q;
string s1[N], s2[N], qs1, qs2;
int main(){
	freopen("replace.in","r", stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i <= q; i++){
		cin >> qs1 >> qs2;
		
		int ans = 0;
		
		for( int j = 1; j<= n; j++){
			int pos = qs1.find(s1[j]);
			if(pos >=0 && pos < qs1.length()){ // 能换
				//cout << endl<< " 能换" << pos<<endl;
				// cout << qs1.substr(0,pos) + s2[j] + qs1.substr(pos + s1[j].size())  << " "<< qs2 << endl; 
				if(qs1.substr(0,pos) + s2[j] + qs1.substr(pos + s1[j].size())   == qs2 )
					ans++;
			}
		}
		cout << ans << endl;
	
	}
	
	return 0;
}
