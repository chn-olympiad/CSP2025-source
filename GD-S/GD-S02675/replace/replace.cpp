#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
string s[N][2],t[N][2];
bool chk(int u,int v){
	for(int i = u; i <= v; i ++){
		if(t[i][1]!=t[i][2]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> s[i][1] >> s[i][2];
	for(int i = 1; i <= q; i ++){
		cin >> t[i][1] >> t[i][2];
		int cnt = 0;
		for(int j = 1; j <= n; j ++){
			int lens = s[i][1].size();
			int lent = t[i][1].size();
			int pos1 = t[i][1].find(s[j][1]);
			int pos2 = t[i][2].find(s[j][2]);
			if(pos1<0||pos2<0||pos1>n||pos2>n) continue;
			if(pos1 == pos2&&chk(0,pos1-1)&&chk(pos1+lens,lent-1)) {
				cnt++;
//				printf("pos1:%d pos2:%d\n",pos1,pos2);
			} 
		}
		cout << cnt << endl;
	}
	return 0;
}

