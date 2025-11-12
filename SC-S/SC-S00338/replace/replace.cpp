#include<bits/stdc++.h>

using namespace std;

#define x1 maimaim41m41
#define x2 chunithmchu2thm
#define y1 ongeki0n93k1
#define y2 phigrosph9r
#define fi first
#define se second
#define chartohs(x) ((x)-'a'+1)
typedef long long ll;
typedef unsigned long long ull;

const ull mod1 = 998442353;
const ull mod2 = 208520859;
const ull bas1 = 39;
const ull bas2 = 97;
const pair<ull, ull> mod = {mod1, mod2};
const pair<ull, ull> bas = {bas1, bas2};

int n, q;
const int N = 2e5+5;

string ori[N][2];
int orilen[N], oridiff[N], oridiffpos[N];
vector<pair<ull, ull>> prehas[N][2];
string tst[2];
vector<pair<ull, ull>> tstprehas[2];
const int L = 5e6+6;
ull pow1[L], pow2[L];
void inithash(){
	pow1[0] = pow2[0] = 1;
	for(int i=1;i<L;i++){
		pow1[i] = pow1[i-1] * bas1 % mod1;
		pow2[i] = pow2[i-1] * bas2 % mod2;
	}
}

pair<ull, ull> operator * (const pair<ull, ull> &a, const pair<ull, ull> &b){
	return {a.fi*b.fi%mod1, a.se*b.se%mod2};
}
pair<ull, ull> operator + (const pair<ull, ull> &a, const pair<ull, ull> &b){
	return {(a.fi+b.fi)%mod1, (a.se+b.se)%mod2};
}
pair<ull, ull> operator - (const pair<ull, ull> &a, const pair<ull, ull> &b){
	return {(a.fi-b.fi%mod1+mod1)%mod1, (a.se-b.se%mod2+mod2)%mod2};
}

pair<ull, ull> operator + (const pair<ull, ull> &a, const int &b){
	return {(a.fi+b)%mod1, (a.se+b)%mod2};
}
void print(pair<ull, ull> x){
	cout<<x.first<<' '<<x.se;
}
void maisolve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ori[i][0]>>ori[i][1];
		orilen[i] = ori[i][0].size();
		ori[i][0] = "*" + ori[i][0];
		ori[i][1] = "*" + ori[i][1];
		for(int j=1;j<=orilen[i];j++){
			if(ori[i][0][j] != ori[i][1][j]){
				oridiff[i] = chartohs(ori[i][0][j]) * 27 + chartohs(ori[i][1][j]);
				oridiffpos[i] = j;
				break;
			}
		}
		prehas[i][0].resize(orilen[i]+1);
		prehas[i][1].resize(orilen[i]+1);
		prehas[i][0][0] = prehas[i][1][0] = make_pair(0ull, 0ull);
		for(int j=1;j<=orilen[i];j++){
			prehas[i][0][j] = prehas[i][0][j-1] * bas + chartohs(ori[i][0][j]);
			prehas[i][1][j] = prehas[i][1][j-1] * bas + chartohs(ori[i][1][j]);
		}
	}
	for(int cur=1;cur<=q;cur++){
		cin>>tst[0]>>tst[1];
		if(tst[0].size() != tst[1].size()){
			cout<<0<<'\n';
			continue;
		}
		int tstlen = tst[0].size();
		tst[0] = "*" + tst[0];
		tst[1] = "*" + tst[1];
		tstprehas[0].clear(); tstprehas[0].resize(tstlen+1);
		tstprehas[1].clear(); tstprehas[1].resize(tstlen+1);
		for(int i=1;i<=tstlen;i++){
			tstprehas[0][i] = tstprehas[0][i-1] * bas + chartohs(tst[0][i]);
			tstprehas[1][i] = tstprehas[1][i-1] * bas + chartohs(tst[1][i]);
//			print(tstprehas[0][i]); cout<<" - "; print(tstprehas[1][i]); cout<<'\n';
		}
		int curdiff = 0, curdiffpos = 0;
		for(int i=1;i<=tstlen;i++){
			if(tst[0][i] != tst[1][i]){
				curdiff = chartohs(tst[0][i]) * 27 + chartohs(tst[1][i]);
				curdiffpos = i;
				break;
			}
		}
		int curans = 0;
		for(int i=1;i<=n;i++){
//			cout<<"-0\n";
			if(curdiff != oridiff[i]) continue;
//			cout<<"-1\n";
			if(curdiffpos < oridiffpos[i] || (tstlen-curdiffpos) < (orilen[i]-oridiffpos[i])) continue;
//			cout<<"-2\n";
			int pre = curdiffpos - oridiffpos[i]+1;
			int suf = curdiffpos + (orilen[i] - oridiffpos[i]);
//			cout<<"presuf "<<pre<<' '<<suf<<'\n';
			if(tstprehas[0][pre-1] != tstprehas[1][pre-1]) continue;
//			cout<<"-3\n";
			if((tstprehas[0][tstlen] - (tstprehas[0][suf] * make_pair(pow1[tstlen-suf], pow2[tstlen-suf]))) != (tstprehas[1][tstlen] - (tstprehas[1][suf] * make_pair(pow1[tstlen-suf], pow2[tstlen-suf])))) continue;
//			cout<<"-4\n";
			if((tstprehas[0][suf] - tstprehas[0][pre-1] * make_pair(pow1[suf-pre+1], pow2[suf-pre+1])) != prehas[i][0][orilen[i]]) continue;
//			cout<<"-5\n";
			if((tstprehas[1][suf] - tstprehas[1][pre-1] * make_pair(pow1[suf-pre+1], pow2[suf-pre+1])) != prehas[i][1][orilen[i]]) continue;
//			cout<<"Y\n";
			curans ++;
		}
		cout<<curans<<'\n';
	}
}
void duoceclear(){
	
}
int main(){
	 freopen("replace.in", "r", stdin);
	 freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
	int t = 1;
//	cin>>t;
	while(t--){
		inithash();
		maisolve();
		duoceclear();
	}
	return 0;
	
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