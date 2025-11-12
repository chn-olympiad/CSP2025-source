#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

const int N=2e5+5,M=1e6+5;
const ull P=29,P2=1e9+7;

int n,q,tmp1,tmp2,L[N],R[N];
ull p[N],h1[N],h2[N];
vector<ull>hs1[N],hs2[N];
vector<ull>ht1[M],ht2[M];
unordered_map<ull,vector<int>>mp;
string s1[N],s2[N],t1[M],t2[M];

ull Hash(int l,int r,vector<ull> h){
	if(l==0)return h[r];
	return h[r]-h[l-1]*p[r-l+1];
}

void insert(string s1,string s2,int id){
	int l1=s1.size();
	ull last1=0,last2=0;
	for(int i=0;i<l1;++i){
		hs1[id].push_back(last1*P+s1[i]-'a');
		hs2[id].push_back(last2*P+s2[i]-'a');
		last1=last1*P+s1[i]-'a';
		last2=last2*P+s2[i]-'a';
		//if(id==3)cout<<last1<<" "<<last2<<"\n";
	}
	int i,j;
	for(i=0;i<l1;++i)
		if(s1[i]!=s2[i])break;
	for(j=l1-1;j>=0;--j)
		if(s1[j]!=s2[j])break;
	L[id]=i,R[id]=l1-j-1;
	ull cnt1=Hash(i,j,hs1[id]),cnt2=Hash(i,j,hs2[id]);
	mp[cnt1*P2+cnt2].push_back(id);
}

int query(string t1,string t2,int id){
	int l1=t1.size();
	ull last1=0,last2=0;
	for(int i=0;i<l1;++i){
		ht1[id].push_back(last1*P+t1[i]-'a');
		ht2[id].push_back(last2*P+t2[i]-'a');
		last1=last1*P+t1[i]-'a';
		last2=last2*P+t2[i]-'a';
	}
	//cout<<l1<<"\n";
	int i,j;
	for(i=0;i<l1;++i){
		if(t1[i]!=t2[i])break;
	}
	for(j=l1-1;j>=0;--j)
		if(t1[j]!=t2[j])break;
	//cout<<i<<" "<<j<<"\n";
	ull cnt1=Hash(i,j,ht1[id]),cnt2=Hash(i,j,ht2[id]);
	//cout<<cnt1<<" "<<cnt2<<"\n";
	int res=0;
	for(int k=0;k<mp[cnt1*P2+cnt2].size();++k){
		int u=mp[cnt1*P2+cnt2][k];
		int l=i-L[u],r=j+R[u];
		//cout<<u<<"\n";
		if(l<0||r>=l1)continue;
		if(Hash(l,r,ht1[id])==hs1[u][s1[u].size()-1]&&Hash(l,r,ht2[id])==hs2[u][s2[u].size()-1])++res;
	}
	return res;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<N;++i)p[i]=p[i-1]*P;
	for(int i=1;i<=n;++i){
		cin>>s1[++tmp1]>>s2[tmp1];
		if(s1[tmp1]==s2[tmp1]){
			--tmp1;
			continue;
		}
		insert(s1[tmp1],s2[tmp1],tmp1);
	}
	n=tmp1;
	for(int i=1;i<=q;++i){
		cin>>t1[++tmp2]>>t2[tmp2];
		if(t1[tmp2].size()!=t2[tmp2].size()){
			--tmp2;
			cout<<0<<"\n";
			continue;
		}
		cout<<query(t1[tmp2],t2[tmp2],tmp2)<<"\n";
	}
}
