#include<bits/stdc++.h> 
using namespace std;

const int N = 1e6;
int n,q,ans;
string s[N][2];
string t[N][2];
int dif[N][3];

void same(int i,int j,int pos){
	int check = 0;
	while((pos < t[i][0].size() && check<s[j][0].size())&& t[i][0][pos]==s[j][0][check] && t[i][1][pos] == s[j][1][check]){
		pos ++;check++;
	}
	if(check == s[j][0].size())ans ++;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++)cin >> s[i][0] >> s[i][1];
	for(int i = 1;i <= q;i ++)cin >> t[i][0] >> t[i][1];
	for(int i = 1;i <= q;i ++){
		dif[i][0]=-1;
		dif[i][1]=-1;		
		if(t[i][0].size() == t[i][1].size()){
			for(int j = 0;j < t[i][0].size();j ++){
				if(dif[i][0]==-1 && t[i][0][j] != t[i][1][j])dif[i][0] = j;
				if(dif[i][0]!=-1 && t[i][0][j] != t[i][1][j])dif[i][1] = j;
			}
		}
		dif[i][2] = dif[i][1] - dif[i][0] + 1;
	}
	for(int i = 1;i <= q;i ++){
		ans = 0;
		for(int j = 1;j <= n;j ++){
			if(dif[i][2] == 0)break;			
			if(dif[i][2] > s[j][0].size())continue;
			for(int z = 0;z < t[i][0].size();z ++)if(z+s[j][0].size()-1>=dif[i][1])same(i,j,z);
		}
		cout << ans;
		if(i!=q)cout << '\n';
	}
	return 0;
}
