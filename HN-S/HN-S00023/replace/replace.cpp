#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#define LL long long
using namespace std;

const int kMaxN = 2e5+10;
const int kMaxQ = 2e5+10;
const int kMaxL = 5e6+10;
const int kBase = 677;
const int kMod = 1e9+7;

vector<int> ruler[kMaxN],query[kMaxQ];
bool is_zero[kMaxQ];

map<int,map<pair<int,int>,int>> cnt[30][30];

void SolveB(int n,int q){	
	for(int i=0;i<n;i++){
		int ll=-1,rr=-1;
		int lval,rval;
		
		for(int j=0;j<ruler[i].size();j++){
			if(ruler[i][j]>0){
				if(ll==-1){
					lval = ruler[i][j];
					ll=j;
				}
				rr = j;
				rval = ruler[i][j];
			}
		}
		cnt[lval][rval][rr-ll][make_pair(ll,ruler[i].size()-rr)]++;
	}
	for(int i=0;i<q;i++){
		if(is_zero[i]){
			cout<<"0\n";
			continue;
		}
		int ll=-1,rr=-1;
		int lval,rval;
		
		for(int j=0;j<query[i].size();j++){
			if(query[i][j]>0){
				if(ll==-1){
					ll=j;
					lval = query[i][j];
				}
				rr = j;
				rval = query[i][j];
			}
		}
		int ans =0;
		for(auto it:cnt[lval][rval][rr-ll]){
			if(it.first.first<=ll && it.first.second<=query[i].size()-rr){
				ans+=it.second;
			}
		}
		cout<<ans<<"\n";
	}
}

bool IsB(const string &s){
	int cnta=0,cntb=0;
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='a'){
			cnta++;
		}
		if(s[i]=='b'){
			cntb++;
		}
	}
	return (cntb==1) && s.size()==cnta+cntb;
}

vector<int> hash_r[kMaxN],hash_q;
vector<int> base_pow;

void GetHash(const vector<int> &s,vector<int> &h){
	h = s;
	
	for(int i=1;i<h.size();i++){
		h[i] = ((LL)h[i-1] * kBase+h[i])%kMod;
	}
}

bool IsEqual(int st,int en,int hashr){
	int hashq = hash_q[en];
	
	if(st>0){
		hashq = (hashq - (LL)hash_q[st-1] * base_pow[en-st+1])%kMod;
		hashq = (hashq+kMod)%kMod;
	}
	return hashr == hashq;
}

void Solve(int n,int q){
	for(int i=0;i<n;i++){
		GetHash(ruler[i],hash_r[i]);
	}
	int maxql=0;
	
	for(int i=0;i<q;i++){
		maxql = max(maxql,(int)query[i].size());
	}
	base_pow.resize(maxql+1);
	base_pow[0]=1;
	for(int i=1;i<=maxql;i++){
		base_pow[i] = (LL)base_pow[i-1] * kBase % kMod;
	}
	for(int i=0;i<q;i++){
		if(is_zero[i]){
			cout<<"0\n";
			continue;
		}
		GetHash(query[i],hash_q);
		
		int ll,rr;
		
		for(ll=0;;ll++){
			if(query[i][ll]/26!=query[i][ll]%26){
				break;
			}
		}
		for(rr=query[i].size()-1;;rr--){
			if(query[i][rr]/26!=query[i][rr]%26){
				break;
			}
		}
		
		int ans=0;
		for(int j=0;j<n;j++){
			int len = rr-ll+1;
			if(len>ruler[j].size() || ruler[j].size()>query[i].size()){
				continue;
			}
			int dt = ruler[j].size()-len;
			
			for(int k=max(0,ll-dt);k<=ll && k+ruler[j].size()<=query[i].size();k++){
				if(IsEqual(k,k+ruler[j].size()-1,hash_r[j].back())){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	bool is_B = true;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2;
		
		cin>>s1>>s2;
		is_B = is_B && IsB(s1);
		is_B = is_B && IsB(s2);
		ruler[i].resize(s1.size());
		for(int j=0;j<s1.size();j++){
			ruler[i][j] = (s1[j]-'a')*26+(s2[j]-'a');
		}
	}
	for(int i=0;i<q;i++){
		string s1,s2;
		
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			is_zero[i] = true;
			continue;
		}
		is_B = is_B && IsB(s1);
		is_B = is_B && IsB(s2);
		query[i].resize(s1.size());
		for(int j=0;j<s1.size();j++){
			query[i][j] = (s1[j]-'a')*26+(s2[j]-'a');
		}
	}
	
	if(is_B){
		SolveB(n,q);
	}else{
		Solve(n,q);
	}
	return 0;
}
