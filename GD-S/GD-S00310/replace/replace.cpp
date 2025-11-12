#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5;
const int maxl = 5e6;
const int B = 29;
pair<ll,ll> str_map[maxn];
int slen[maxn];
ll pB[maxl],h1[maxl],h2[maxl];
vector<int> fr;
ll hs(string &s){
	ll res=0;
	for(int i=0;i<s.size();i++) res = res*B + (s[i]-'a'+1);
	return res;
}
void init(){
	memset(h1,0,sizeof(h1));
	memset(h2,0,sizeof(h2));
	vector<int>().swap(fr);
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q; cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2; cin>>s1>>s2;
		str_map[i] = make_pair(hs(s1),hs(s2));
		slen[i] = s1.size();
	}
	while(q--){
		init();
		string t1,t2; cin>>t1>>t2;
		int l1=t1.size(), l2=t2.size();
		if(l1!=l2){
			cout<<0;
			continue;
		}
		h1[0] = t1[0]-'a'+1;
		h2[0] = t2[0]-'a'+1;
		if(h1[0]==h2[0]) fr.push_back(1);
		pB[0] = 1;
		for(int i=1;i<l1;i++){
			h1[i] = h1[i-1]*B + t1[i]-'a'+1;
			h2[i] = h2[i-1]*B + t2[i]-'a'+1;
			if(h1[i]==h2[i]) fr.push_back(i+1);
			if(!pB[i]) pB[i] = pB[i-1]*B;
		}
		int cnt=0;
		for(int si=0;si<n;si++){
			int sl = slen[si];
			if(
				(h1[sl-1]==str_map[si].first) && 
				(h1[l1-1]-h1[sl-1]*pB[l1-sl]==h2[l1-1]-h2[sl-1]*pB[l1-sl]) && 
				(h2[sl-1]==str_map[si].second)
			) cnt++;
		}
		for(auto i : fr){
			i--;
			for(int si=0;si<n;si++){
				int sl = slen[si];
				if(
					(h1[i+sl]-h1[i]*pB[sl]==str_map[si].first) && 
					(h1[l1-1]-h1[i+sl]*pB[l1-1-i-sl]==h2[l1-1]-h2[i+sl]*pB[l1-1-i-sl]) && 
					(h2[i+sl]-h2[i]*pB[sl]==str_map[si].second)
				) cnt++;
			}
			i++;
		}
		cout<<cnt<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
