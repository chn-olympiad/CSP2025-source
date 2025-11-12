#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define MAXM 5000010
#define MAXN 200010
const int del=5000000;
int n,q;
string s1[MAXN],s2[MAXN];
map<pair<string,string>,int>ds;
vector<int>p[MAXM],qs[MAXM];
int b[MAXN],c[MAXM*2],sum[MAXN];
#define lowbit(i) i&(-i)
void add(int x,int y){
	c[x]+=y;
}
int query(int x){
	return c[x];
}
int find(string s){
	int p1=0;
	for(int j=0;j<s.length();j++)
		if(s[j]=='b')p1=j;
	return p1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n>=1000&&q>1){
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			int p1=find(s1[i]),p2=find(s2[i]);
			p[s1[i].length()].push_back(p1-p2); 
		}
		for(int i=1;i<=q;i++){
			string t1,t2;
			cin>>t1>>t2;
			int p1=find(t1),p2=find(t2);
			b[i]=p1-p2;
			qs[(int)t1.length()].push_back(i);
		}
		for(int i=0;i<=del;i++){
			for(auto j:p[i])
				add(j+del,1);
			for(auto j:qs[i])
				sum[j]=query(b[j]+del);
		}
		for(int i=1;i<=q;i++)
			cout<<sum[i]<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		ds[mp(s1[i],s2[i])]++;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int l=0,r=t1.length()-1;
		while(l<t1.length()-1&&t1[l]==t2[l])
			l++;
		while(r>0&&t1[r]==t2[r])
			r--;
		int ans=0;
		for(int i=0;i<=l;i++){
			for(int len=1;i+len-1<t1.length();len++){
				if(i+len-1<r)continue;
				string s=t1.substr(i,len);
				string t=t2.substr(i,len);
				ans+=ds[mp(s,t)];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
