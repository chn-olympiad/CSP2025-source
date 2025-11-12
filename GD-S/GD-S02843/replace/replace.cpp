#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int n,q;
string S1[200005],S2[200005];
string T1,T2;
string str;
int chg[200005][2];
int tru[200005][3],ans;
bool hav;
struct trie{
	int son[30];
	vector<int> end;
}SL[200005],SR[200005];
int cntL,cntR;
map<pair<int,int>,vector<int>> M;
int num(char a){
	return (int)(a-'a');
}
int HASH(string s,int l,int r){
	int a=0;
	for(int i=l;i<=r;i++){
		a*=31;
		a+=num(s[i]);
		a %= 1000000007;
	}
	return a;
}
void build(string s,int id,int k){
	int p=0;
	if(id == 1){
		for(int i=0;s[i];i++){
			if(SL[p].son[num(s[i])] == 0)SL[p].son[num(s[i])] = ++cntL;
			p = SL[p].son[num(s[i])];
		}
		SL[p].end.push_back(k); 
	}
	if(id == 2){
		for(int i=0;s[i];i++){
			if(SR[p].son[num(s[i])] == 0)SR[p].son[num(s[i])] = ++cntR;
			p = SR[p].son[num(s[i])];
		}
		SR[p].end.push_back(k); 
	}	
}
void find(string s,int id){
	int p=0;
	if(id == 1){
		for(auto i:SL[p].end)tru[i][1] = q+1;
		for(int i=0;s[i];i++){
			if(SL[p].son[num(s[i])] == 0)return;;
			p = SL[p].son[num(s[i])];
			for(auto i:SL[p].end)tru[i][1] = q+1;
		}
	}
	if(id == 2){
		for(auto i:SR[p].end){
			tru[i][2] = q+1;
			if(tru[i][0] == q+1 and tru[i][1] == q+1)ans++;
		}
		for(int i=0;s[i];i++){
			if(SR[p].son[num(s[i])] == 0)return;
			p = SR[p].son[num(s[i])];
			for(auto i:SR[p].end){
				tru[i][2] = q+1;
				if(tru[i][0] == q+1 and tru[i][1] == q+1)ans++;
			}
		}
	}
}
void solve(string S,string T){
	ans = 0;
	if(S.length() != T.length()){
		printf("0\n");
		return;
	}
	S = " "+S;
	T = " "+T;
	int len = S.length()-1;
	int l=1,r=len;
	while(S[l] == T[l])l++;
	while(S[r] == T[r])r--;
	int s = HASH(S,l,r);
	int t = HASH(T,l,r);
	hav = false;
	for(auto i:M[mp(s,t)]){
		tru[i][0] = q+1;
		hav = true;
	}
	if(!hav){
		printf("0\n");
		return;
	}
	str = "";
	for(int i=l-1;i>=1;i--)str = str + S[i];
	find(str,1);
	str = "";
	for(int i=r+1;i<=len;i++)str = str + S[i];
	find(str,2);
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin >> S1[i] >> S2[i];
		S1[i] = " "+S1[i];
		S2[i] = " "+S2[i];
		chg[i][0] = 1;
		chg[i][1] = S1[i].length()-1;
		while(S1[i][chg[i][0]] == S2[i][chg[i][0]])chg[i][0]++;
		while(S1[i][chg[i][1]] == S2[i][chg[i][1]])chg[i][1]--;
		M[mp(HASH(S1[i],chg[i][0],chg[i][1]),HASH(S2[i],chg[i][0],chg[i][1]))].push_back(i);
		str = "";
		for(int j=chg[i][0]-1;j>=1;j--)str = str + S1[i][j];
		build(str,1,i);
		str = "";
		for(int j=chg[i][1]+1;j<=S1[i].length()-1;j++)str = str + S1[i][j];
		build(str,2,i);
	}
	while(q--){
		cin >> T1 >> T2;
		solve(T1,T2);
	}
	return 0;
}

//CCF评测机发力啊，这玩意本地replace4 1.2s（不是正解） 
