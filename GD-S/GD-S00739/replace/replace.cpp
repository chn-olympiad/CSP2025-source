#include <bits/stdc++.h>
using namespace std;
const int maxv=5000000;
class Fnew{
public:
	int n;
	vector<int>tree;
	Fnew(int n):n(n),tree(n+1,0){}
	void update(int i,int delta){
		while(i<=n){
			tree[i]+=delta;
			i+=i& -i;
		}
	}
	int query(int i){
		if(i<=0)return 0;
		if(i>n)i=n;
		int sum=0;
		while(i){
			sum+=tree[i];
			i -= i & -i;
		}
		return sum;
	}
};
int fbp(const string& s){
	for(int i=0;i<s.length();i++){
		if(s[i]=='b')return i;
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	unordered_map<int,vector<pair<string,string>>>rbd;
	for(int i=0;i<n;i++){
		string sa,sb;
		cin>>sa>>sb;
		int Lr=sa.length();
		int pa=fbp(sa);
		int pb=fbp(sb);
		int de=pb-pa;
		rbd[de].push_back({pa,Lr});
	}
	vector<int>ans(q,0);
	unordered_map<int,vector<tuple<int,int,int>>>qbd;
	for(j=0;j<q;j++){
		string ta,tb;
		cin>>ta>>tb;
		int L=ta.length();
		if(tb.length()!=L){
			ans[j]=0;
			continue;
		}
		int pos1=fdp(ta);
		int pos2=fdq(tb);
		int de=pos2-pos1;
		qbd[de].push_back({pos1,L-pos1,j});
	}
	Fnew fnew(maxv);
	for(auto& entry:rbd){
		int de=entry.first;
		auto&rules=entry.second;
		if(qbd.find(de)==qbd.end())continue;
		auto& qu=qbd[de];
		sort(rules.begin(),rules.end(),[](const pair<int,int>&a,const pair<int,int>& b){
			return a.first<b.first;
		});
		sort(qu.begin(),qu.end(),[](const tuple<int,int>&a,const tuple<int,int>& b){
			return get<0>(a) < get<0>(b);
		});
		int idx=0;
		for(auto& query:qu){
			int pos1=get<0>(query);
			int c=get<1>(query);
			int id=get<2>(query);
			while(idx<rules.size()&&rules[idx].first<=pos1){
				int v=rules[idx].second-rules[idx].first;
				if(v>=1&&v<=maxv)fnew.update(v,1);
				idx++;
			}
			ans[id]=fnew.query(c);
		}
		while(idx>0){
			idx--;
			int v=rules[idx].second-rules[idx].first;
			if(v>=1&&v<=maxv)fnew.update(v,-1);
		}
	}
	for(int j=0;j<q;j++)cout<<ans[j]<<endl;
	return 0;
}

