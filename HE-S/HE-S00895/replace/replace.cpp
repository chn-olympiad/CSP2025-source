#include"bits/stdc++.h"
using namespace std;
const int maxn = 2e5+10;
const int maxLn = 5e6+10;
typedef long long Lo;
typedef __int128 XI;
const Lo mo = 1926081719491001071ll;
const int Bs = 121;
int n,q,Ans[maxn];
string S[2];
namespace Trie2{
	struct Node{
		int s[26];
		int Ed;
	}Tr[maxLn];
	int TIx=1;
	void Insert(string S){
		int x=1;
		for(auto I:S){
			int c=I-'a';
			if(!Tr[x].s[c])Tr[x].s[c]=++TIx;
			x=Tr[x].s[c];
		}
		Tr[x].Ed++;
	}
	void Delete(string S){
		int x=1;
		for(auto I:S){
			int c=I-'a';
			if(!Tr[x].s[c])Tr[x].s[c]=++TIx;
			x=Tr[x].s[c];
		}
		Tr[x].Ed--;
	}
	void Query(string S,int Id){
		Ans[Id]+=Tr[1].Ed;
		int x=1;
		for(auto I:S){
			int c=I-'a';
			x=Tr[x].s[c];
			Ans[Id]+=Tr[x].Ed;
		}
	}
}
namespace Trie{
	struct Node{
		vector<string>Rep;
		vector<pair<string,int>>Q;
		int s[26];
	}Tr[maxLn];
	int TIx=1;
	void Insert(string L,string R){
		int x=1;
		for(auto I:L){
			int c=I-'a';
			if(!Tr[x].s[c])Tr[x].s[c]=++TIx;
			x=Tr[x].s[c];
		}
		Tr[x].Rep.push_back(R);
	}
	void InsertQ(string L,string R,int Id){
		int x=1;
		for(auto I:L){
			int c=I-'a';
			if(!Tr[x].s[c]){
				Tr[x].Q.push_back({R,Id});
				return;
			}
			x=Tr[x].s[c];
		}
		Tr[x].Q.push_back({R,Id});
	}
	void Traverse(int x){
		for(auto I:Tr[x].Rep)
			Trie2::Insert(I);
		for(auto I:Tr[x].Q)
			Trie2::Query(I.first,I.second);
		for(int i=0;i<26;i++)
			if(Tr[x].s[i])
				Traverse(Tr[x].s[i]);
		for(auto I:Tr[x].Rep)
			Trie2::Delete(I);
	}
	void Clear(){
		for(int i=1;i<=TIx;i++){
			Tr[i].Rep.clear(),Tr[i].Q.clear();
			for(int j=0;j<26;j++)
				Tr[i].s[j]=0;
		}
		TIx=1;
	}
}
struct Query{
	string L,R;
	int Id;
};
struct Sub{
	vector<Query> Q;
	vector<pair<string,string>> Rep;
};
map<pair<Lo,Lo>,Sub>Mp;
int main(){
	//system("fc replace.out replace4.ans");
	freopen("replace.in","r",stdin);
	//freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	//freopen("log.txt","w",stderr);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>S[0]>>S[1];
		if(S[0]==S[1])continue;
		int L=0,R=S[0].size()-1;
		Lo H_0=0,H_1=0;
		while(S[0][L]==S[1][L])L++;
		while(S[0][R]==S[1][R])R--;
		string Ls="",Rs="";
		for(int j=0;j<L;j++)Ls+=S[0][j];
		for(int j=R+1;j<S[0].length();j++)Rs+=S[0][j];
		for(int j=L;j<=R;j++){
			H_0=((((XI)H_0)*Bs)%mo+S[0][j]-'a'+1)%mo;
			H_1=((((XI)H_1)*Bs)%mo+S[1][j]-'a'+1)%mo;
		}
		reverse(Ls.begin(),Ls.end());
		Mp[{H_0,H_1}].Rep.push_back({Ls,Rs});
	}
	for(int i=1;i<=q;i++){
		cin>>S[0]>>S[1];
		int L=0,R=S[0].size()-1;
		Lo H_0=0,H_1=0;
		while(S[0][L]==S[1][L])L++;
		while(S[0][R]==S[1][R])R--;
		string Ls="",Rs="";
		for(int j=0;j<L;j++)Ls+=S[0][j];
		for(int j=R+1;j<S[0].length();j++)Rs+=S[0][j];
		for(int j=L;j<=R;j++){
			H_0=((((XI)H_0)*Bs)%mo+S[0][j]-'a'+1)%mo;
			H_1=((((XI)H_1)*Bs)%mo+S[1][j]-'a'+1)%mo;
		}
		reverse(Ls.begin(),Ls.end());
		Mp[{H_0,H_1}].Q.push_back({Ls,Rs,i});
	}
	for(auto T:Mp){
		for(auto p:T.second.Rep)Trie::Insert(p.first,p.second);
		for(auto p:T.second.Q)Trie::InsertQ(p.L,p.R,p.Id);
		Trie::Traverse(1),Trie::Clear();
	}
	for(int i=1;i<=q;i++)
		cout<<Ans[i]<<'\n';
}
