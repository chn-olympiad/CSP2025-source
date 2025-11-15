#include <bits/stdc++.h>
using namespace std;

const int MAX_N_Q = 200009;
const int MAX_L = 5000009;

struct node1{
	int l=MAX_N_Q,r=-1;
	vector<int> to,end;
	node1(){
		to.resize(26,-1);
	}
};

struct node2{
	int tag1=0,tag2=0,l=MAX_N_Q,r=-1;
	vector<int> to,end;
	node2(){
		to.resize(26,-1);
	}
};

int n,q,cur,tmp=1,pt;
vector<node1> trie1;
vector<node2> trie2;
vector<pair<string,string>> s,t;
stack<int> dfs;
vector<int> order(1,-1),sl,sr,tl,tr,ans,da;
vector<vector<pair<bool,int>>> query;

void solve(){
	cin >> n >> q;
	s.resize(n);trie1.resize(MAX_L);sl.resize(n,-1);sr.resize(n,-1);tl.resize(q,-1);tr.resize(q,-1);
	t.resize(q);ans.resize(q,0);query.resize(MAX_N_Q);trie2.resize(MAX_L);da.resize(MAX_N_Q);
	for(int i=0;i<n;i++){
		cin >> s[i].first >> s[i].second;
		for(int j=0;j<s[i].first.size();j++){
			if(s[i].first[j]!=s[i].second[j]){
				sl[i]=j;
				break;
			}
		}
		if(sl[i]==-1){
			continue;
		}
		for(int j=s[i].first.size()-1;j>=0;j--){
			if(s[i].first[j]!=s[i].second[j]){
				sr[i]=j;
				break;
			}
		}
	}
	for(int i=0;i<q;i++){
		cin >> t[i].first >> t[i].second;
		if(t[i].first.size()!=t[i].second.size()){
			continue;
		}
		for(int j=0;j<t[i].first.size();j++){
			if(t[i].first[j]!=t[i].second[j]){
				tl[i]=j;
				break;
			}
		}
		for(int j=t[i].first.size()-1;j>=0;j--){
			if(t[i].first[j]!=t[i].second[j]){
				tr[i]=j;
				break;
			}
		}
		cur=1;
		for(int j=tr[i];j>=0;j--){
			if(trie1[cur].to[t[i].first[j]-'a']==-1){
				trie1[cur].to[t[i].first[j]-'a']=++tmp;
			}
			cur=trie1[cur].to[t[i].first[j]-'a'];
		}
		trie1[cur].end.push_back(i);
	}
	dfs.push(1);
	while(!dfs.empty()){
		tmp=dfs.top();
		dfs.pop();
		if(tmp<0){
			tmp=-tmp;
			for(int i=25;i>=0;i--){
				if(trie1[tmp].to[i]!=-1){
					trie1[tmp].l=min(trie1[tmp].l,trie1[trie1[tmp].to[i]].l);
					trie1[tmp].r=max(trie1[tmp].r,trie1[trie1[tmp].to[i]].r);
				}
			}
			continue;
		}
		dfs.push(-tmp);
		if(trie1[tmp].end.size()!=0){
			trie1[tmp].l=order.size();
		}
		for(int i=0;i<trie1[tmp].end.size();i++){
			order.push_back(trie1[tmp].end[i]);
		}
		if(trie1[tmp].end.size()!=0){
			trie1[tmp].r=order.size()-1;
		}
		for(int i=25;i>=0;i--){
			if(trie1[tmp].to[i]!=-1){
				dfs.push(trie1[tmp].to[i]);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(sl[i]==-1){
			continue;
		}
		cur=1;
		for(int j=sr[i];j>=0;j--){
			cur=trie1[cur].to[s[i].first[j]-'a'];
			if(cur==-1){
				break;
			}
		}
		if(cur!=-1){
			query[trie1[cur].l-1].push_back({false,i});
			query[trie1[cur].r].push_back({true,i});
		}
	}
	tmp=1;
	for(int i=1;i<order.size();i++){
		cur=1;pt=order[i];
		for(int j=tl[pt];j<t[pt].second.size();j++){
			if(trie2[cur].to[t[pt].second[j]-'a']==-1){
				trie2[cur].to[t[pt].second[j]-'a']=++tmp;
				trie2[tmp].tag2-=trie2[cur].tag1;
			}
			cur=trie2[cur].to[t[pt].second[j]-'a'];
		}
		trie2[cur].end.push_back(pt);
		for(int j=0;j<query[i].size();j++){
			pt=query[i][j].second;
			cur=1;
			for(int k=sl[pt];k<s[pt].second.size();k++){
				cur=trie2[cur].to[s[pt].second[k]-'a'];
				if(cur==-1){
					break;
				}
			}
			if(cur!=-1){
				if(query[i][j].first){
					trie2[cur].tag1++;
				}else{
					trie2[cur].tag1--;
				}
			}
		}
	}
	order={-1};
	dfs.push(1);
	while(!dfs.empty()){
		tmp=dfs.top();
		dfs.pop();
		if(tmp<0){
			tmp=-tmp;
			for(int i=25;i>=0;i--){
				if(trie2[tmp].to[i]!=-1){
					trie2[tmp].l=min(trie2[tmp].l,trie2[trie2[tmp].to[i]].l);
					trie2[tmp].r=max(trie2[tmp].r,trie2[trie2[tmp].to[i]].r);
				}
			}
			if(trie2[tmp].l<=trie2[tmp].r){
				da[trie2[tmp].l]+=trie2[tmp].tag1+trie2[tmp].tag2;
				da[trie2[tmp].r+1]-=trie2[tmp].tag1+trie2[tmp].tag2;
			}
			continue;
		}
		dfs.push(-tmp);
		if(trie2[tmp].end.size()!=0){
			trie2[tmp].l=order.size();
		}
		for(int i=0;i<trie2[tmp].end.size();i++){
			order.push_back(trie2[tmp].end[i]);
		}
		if(trie2[tmp].end.size()!=0){
			trie2[tmp].r=order.size()-1;
		}
		for(int i=25;i>=0;i--){
			if(trie2[tmp].to[i]!=-1){
				dfs.push(trie2[tmp].to[i]);
			}
		}
	}
	tmp=0;
	for(int i=1;i<order.size();i++){
		tmp+=da[i];
		ans[order[i]]=tmp;
	}
	for(int i=0;i<q;i++){
		cout << ans[i] << '\n';
	}
}

int32_t main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	// cin >> T;
	while(T--){
		solve();
	}
}