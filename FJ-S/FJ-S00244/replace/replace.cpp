#include <bits/stdc++.h>
#define ll long long
const int N = 1e5+10;
using namespace std;
int n,q,ans;
string s1[N],s2[N],t1,t2; 
int match(int x){
	for(int i = 0;i < t1.size();i++){
		
		for(int j = 0;j < s1[x].size();j++){
			if(t1[i] != s1[x][j])
				break;
			int flag = 1;
			if(j+1 == s1[x].size()){
				for(int k = 0;k < i;k++){
					if(t1[k] != t2[k])
						flag = 0;
				}
				for(int k = i;k < i+j;k++)
					if(s1[x][k] != t2[k])
						flag = 0;
				for(int k = i+j;k < t1.size();k++)
					if(t1[k] != t2[k])
						flag = 0;
			}	
			if(flag)
				ans++;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> s1[i] >> s2[i];
	for(int i = 1;i <= n;i++){
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			cout << 0 << '\n';
			continue;
		}
		ans = 0;
		for(int j = 1;j <= n;j++){
			match(j);
		}
		cout << ans << '\n';
	}
	return 0;
}

