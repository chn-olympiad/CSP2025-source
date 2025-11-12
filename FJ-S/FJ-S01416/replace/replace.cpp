#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
//map<string,int> s;
string trs[N][2];
string d1,d2;
int n,q,flag[N];
bool cmp(string a,string b,int i,int j,int l){
	for(int x=0;x<l;x++){
		if(a[x+i] != b[x+j]){
			return false;
		}
	}
	return true;
}
int dfs(string pre){
	if(pre.size() == d2.size() && cmp(pre,d2,0,0,pre.size())){
		return 1;
	}
//	cout << pre << '\n';
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(flag[i] == 1)continue;
		int tag = -1;
//			cout << pre << ' ' << trs[i][0] << '\n';
		for(int j=0;j+trs[i][0].size()<=pre.size();j++){
//			cout << j << ' ' << 0 << ' ' << trs[i][0].size() << '\n';
			if(cmp(pre,trs[i][0],j,0,trs[i][0].size())){
				tag = j;
				break;
			}
		}
		if(tag != -1){
			flag[i] = 1;
			string cur = "";
			for(int k=0;k<tag;k++){
				cur += pre[k];
			}
			cur += trs[i][1];
			for(int k=tag+trs[i][0].size();k<pre.size();k++){
				cur += pre[k];
			}
//			cout << "cur:" << cur << '\n';
			cnt += dfs(cur);
			flag[i] = 0;
		}
	}
//	s[pre] += cnt;
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> trs[i][0] >> trs[i][1];
	}
//	s.clear();
	for(int i=1;i<=q;i++){
		cin >> d1 >> d2;
		cout << dfs(d1) << '\n';
	}
	return 0;
}
