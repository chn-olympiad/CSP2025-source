#include<bits/stdc++.h>
using namespace std;
const int N=5e6+7;
const int M=2e5+7;
struct Trie{
	struct node{
		vector<int>id;
		int nxt[27];
	}a[N];
	int idx=1;
	void insert(string& s,int id){
		int cur=1,len=s.size();
		for(int i=0;i<len;i++){
			int ch=s[i]-'a';
			if(a[cur].nxt[ch]==0) a[cur].nxt[ch]=++idx;
			cur=a[cur].nxt[ch];
		}
		a[cur].id.push_back(id);
		return;
	}
	void check(string& s,vector<int>&res){
		int cur=1,len=s.size();
		res.clear();res.shrink_to_fit();
		for(int i=0;i<len;i++){
			int ch=s[i]-'a';
			if(a[cur].nxt[ch]==0) return;
			cur=a[cur].nxt[ch];
		}
		res=a[cur].id;
		return;
	}
};
struct node{
	string s1,s2;
	string pre,nxt;
	int len;
	void make(string& t1,string& t2){
		s1=s2=pre=nxt="";
		len=t1.size();
		for(int i=0;i<len;i++){
			if(t1[i]==t2[i]) pre+=t1[i];
			else break;
		}
		for(int i=len-1;i>=0;i--){
			if(t1[i]==t2[i]) nxt+=t1[i];
			else break;
		}
		int l=nxt.size();
		int ll=pre.size(),rr=len-nxt.size();
		for(int i=ll;i<rr;i++){
			s1+=t1[i],s2+=t2[i];
		}
		return;
	}
}a[M];
node tmp;
Trie t1,t2;
int n,q;
bool check(string& s1,string& s2){
	int l1=s1.size(),l2=s2.size();
	for(int i=l1-1,j=l2-1;i>=0&&j>=0;i--,j--){
		if(s1[i]!=s2[j]){
			return false;
		}
	}
	return true;
}
int solve(string& s1,string& s2){
	vector<int>r1;
	vector<int>r2;
	tmp.make(s1,s2);
	t1.check(tmp.s1,r1);
	t2.check(tmp.s2,r2);
	vector<int>res;
	while((!r1.empty())&&(!r2.empty())){
		if(r1.back()==r2.back()){
			res.push_back(r1.back());
			r1.pop_back();
			r2.pop_back();
		}else if(r1.back()>r2.back()){
			r1.pop_back();
		}else r2.pop_back();
	}
	int cnt=0;
	for(auto id:res){
		if(tmp.pre.size()<a[id].pre.size()) continue;
		if(tmp.nxt.size()<a[id].nxt.size()) continue;
		int l=a[id].nxt.size();
		bool flag=false;
		for(int i=0;i<l;i++){
			if(tmp.nxt[i]!=a[id].nxt[i]){
				flag=true;
				break;
			}
		}
		if(check(tmp.nxt,a[id].nxt)==false) continue;
		if(check(tmp.pre,a[id].pre)==false) continue;
		cnt++;
	}
	return cnt;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string tmp1,tmp2;
	for(int i=1;i<=n;i++){
		cin>>tmp1>>tmp2;
		a[i].make(tmp1,tmp2);
		t1.insert(a[i].s1,i);
		t2.insert(a[i].s2,i);
	}
	for(int i=1;i<=q;i++){
		cin>>tmp1>>tmp2;
		cout<<solve(tmp1,tmp2)<<"\n";
	}
	return 0;
}
