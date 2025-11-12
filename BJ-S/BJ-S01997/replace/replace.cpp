#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int MX = 2e5 + 7;
const int MXN = 5e6 + 7;
const ull B = 1145141;
string xs[MX],zs[MX],xt[MX],zt[MX];
int ans[MX];
ull ys[MX],yt[MX];bool fs[MX],ft[MX];
ull vals[MX << 1],tot = 0;
ull hs(string s){
	ull ret = 0;
	for(int i = 0;i < s.size();i++)ret = ret * B + s[i];
	return ret;
}
vector<int > bucs[MX << 1],buct[MX << 1];
map<char,int > ch1[MXN],ch2[MXN];
vector<int > qs[MXN],qt[MXN];int sum[MX];
int tNode1 = 0,tNode2 = 0;
void clearmp(map<char,int > &x){
	map<char,int > tmp;
	swap(x,tmp);
}
void clearvt(vector<int > &x){
	vector<int > tmp;
	swap(x,tmp);
}
bool tr(int x,int y){
	if(xs[x].size() <= xt[y].size() && zs[x].size() <= zt[y].size()){
		for(int i = 0,p1 = xs[x].size() - 1,p2 = xt[y].size() - 1;i < xs[x].size();i++,p1--,p2--){
			if(xs[x][p1] != xt[y][p2])return false;
		}
		for(int i = 0;i < zs[x].size();i++)
			if(zs[x][i] != zt[y][i])return false;
		return true;
	}
	else return false;
}
void dfs(int x){
	for(auto it : qs[x]){
		int p = 1;
		for(int i = 0;i < zs[it].size();i++){
			char c = zs[it][i];
			if(ch2[p].find(c) == ch2[p].end()){
				++tNode2;clearmp(ch2[tNode2]);sum[tNode2] = 0;
				ch2[p][c] = tNode2;
			}
			p = ch2[p][c];
		}
		sum[p]++;
	}
	for(auto it : qt[x]){
		int p = 1;bool flg = false;
		for(int i = 0;i < zt[it].size();i++){
			char c = zt[it][i];ans[it] += sum[p];
			if(ch2[p].find(c) == ch2[p].end()){flg = true;break;}
			p = ch2[p][c];
		}
		if(!flg)ans[it] += sum[p];
	}
	for(auto it : ch1[x])dfs(it.second);
	for(auto it : qs[x]){
		int p = 1;
		for(int i = 0;i < zs[it].size();i++){char c = zs[it][i];p = ch2[p][c];}
		sum[p]--;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios :: sync_with_stdio(false);
	int n,q;cin >> n >> q;
	for(int i = 1;i <= n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		if(s1 == s2){fs[i] = true;continue;}
		int pl,pr;
		for(int j = 0;j < s1.size();j++)
			if(s1[j] != s2[j]){pl = j;break;}
		for(int j = s1.size() - 1;j >= 0;j--)
			if(s1[j] != s2[j]){pr = j;break;}
		string cury = s1.substr(pl,pr - pl + 1) + s2.substr(pl,pr - pl + 1);
		ys[i] = hs(cury);vals[++tot] = ys[i];
		xs[i] = "";zs[i] = "";
		for(int j = 0;j < pl;j++)xs[i] += s1[j];
		for(int j = pr + 1;j < s1.size();j++)zs[i] += s1[j];
	}
	for(int i = 1;i <= q;i++){
		string t1,t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){ft[i] = true;continue;}
		int pl,pr;
		for(int j = 0;j < t1.size();j++)
			if(t1[j] != t2[j]){pl = j;break;}
		for(int j = t1.size() - 1;j >= 0;j--)
			if(t1[j] != t2[j]){pr = j;break;}
		string cury = t1.substr(pl,pr - pl + 1) + t2.substr(pl,pr - pl + 1);
		yt[i] = hs(cury);vals[++tot] = yt[i];
		xt[i] = "";zt[i] = "";
		for(int j = 0;j < pl;j++)xt[i] += t1[j];
		for(int j = pr + 1;j < t1.size();j++)zt[i] += t1[j];
	}
	sort(vals + 1,vals + 1 + tot);tot = unique(vals + 1,vals + 1 + tot) - vals - 1;
	for(int i = 1;i <= n;i++)
		if(!fs[i])bucs[lower_bound(vals + 1,vals + 1 + tot,ys[i]) - vals].push_back(i);
	for(int i = 1;i <= q;i++)
		if(!ft[i])buct[lower_bound(vals + 1,vals + 1 + tot,yt[i]) - vals].push_back(i);
	for(int C = 1;C <= tot;C++){
		if(bucs[C].empty() || buct[C].empty())continue;
		tNode1 = tNode2 = 0;
		++tNode1;++tNode2;
		clearmp(ch1[1]);clearmp(ch2[1]);
		clearvt(qs[1]);clearvt(qt[1]);sum[1] = 0;
		for(int i = 0;i < bucs[C].size();i++){
			int p = 1,id = bucs[C][i];
			if(xs[id].size() != 0){
				for(int j = xs[id].size() - 1;j >= 0;j--){
					char c = xs[id][j];
					if(ch1[p].find(c) == ch1[p].end()){
						++tNode1;clearmp(ch1[tNode1]);clearvt(qs[tNode1]);clearvt(qt[tNode1]);
						ch1[p][c] = tNode1;
					}
					p = ch1[p][c];
				}
			}
			qs[p].push_back(id);
		}
		for(int i = 0;i < buct[C].size();i++){
			int p = 1,id = buct[C][i];
			if(xt[id].size() != 0){
				for(int j = xt[id].size() - 1;j >= 0;j--){
					char c = xt[id][j];
					if(ch1[p].find(c) == ch1[p].end())break;
					p = ch1[p][c];
				}
			}
			qt[p].push_back(id);
		}
		dfs(1);
	}
	for(int i = 1;i <= q;i++)cout << ans[i] << '\n';
	return 0;
}