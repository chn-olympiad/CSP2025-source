#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4,M=5e6+4;
int n,q,p[2][M];
string u,v,s[N][2];
vector<int> pi[N][2];
void kmp(const string &s,vector<int> &pi){
	int len=s.size();
	pi=vector<int>(len);
	for(int i=1;i<len;i++){
		int j=pi[i-1];
		while(j&&s[i]!=s[j])j=pi[j-1];
		if(s[i]==s[j])j++;
		pi[i]=j;
	}
}
int f1(int i,const vector<int> &a,int b[M],int len){
	if(i<len)return a[i];
	if(i==len)return 0;
	return b[i-len-1];
}
char f2(int i,const string &a,const string &b,int len){
	if(i<len)return a[i];
	if(i==len)return '@';
	return b[i-len-1];
}
void solve(){
	cin>>u>>v;
	if(u.size()!=v.size()){
		cout<<"0\n";
		return;
	}
	int len=u.size(),pos0=0,pos1=len;
	while(pos0<len&&u[pos0]==v[pos0])pos0++;
	while(pos1&&u[pos1-1]==v[pos1-1])pos1--;
	int ans=0;
	for(int i=1;i<=n;i++){
		int len1=s[i][0].size();
		if(len1>len||pos1-len1>pos0)continue;
		for(int j=len1+1;j<=len+len1;j++){
			int k=f1(j-1,pi[i][0],p[0],len1);
			while(k&&f2(j,s[i][0],u,len1)!=f2(k,s[i][0],u,len1))k=f1(k-1,pi[i][0],p[0],len1);
			if(f2(j,s[i][0],u,len1)==f2(k,s[i][0],u,len1))k++;
			p[0][j-len1-1]=k;
		}
		for(int j=len1+1;j<=len+len1;j++){
			int k=f1(j-1,pi[i][1],p[1],len1);
			while(k&&f2(j,s[i][1],v,len1)!=f2(k,s[i][1],v,len1))k=f1(k-1,pi[i][1],p[1],len1);
			if(f2(j,s[i][1],v,len1)==f2(k,s[i][1],v,len1))k++;
			p[1][j-len1-1]=k;
		}
		for(int j=max(0,pos1-len1);j<=pos0&&j+len1<=len;j++)ans+=p[0][j+len1-1]==len1&&p[1][j+len1-1]==len1;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		kmp(s[i][0],pi[i][0]);
		kmp(s[i][1],pi[i][1]);
	}
	while(q--)solve();
}
