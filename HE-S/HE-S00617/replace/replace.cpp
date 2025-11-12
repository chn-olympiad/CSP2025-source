#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,m;
string s1[N],s2[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
	}
	while(m--){
		string si,sj;
		cin >> si >> sj;
		int ans = 0;
		int l = si.size();
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < l-s1[i].size()+1;j++){
				string ci = si.substr(j,j+s1[i].size()),cj = sj.substr(j,j+s2[i].size());
				if(ci == s1[i] && cj == s2[i]) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
