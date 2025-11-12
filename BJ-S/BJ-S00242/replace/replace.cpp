#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
const int MOD=998244853;

struct A{int len,cnt;ull hsh1,hsh2;};

int n,m,T;
string s,t;
int tr[5000010][27],ltp=1;
vector<A> b[5000010];
int c[5000010],cnt;
ull f[5000010][2];

int insert(){
	int p=1;
	for(int i=1;i<=cnt;i++){
		if(!tr[p][c[i]]) ltp++,tr[p][c[i]]=ltp;
		p=tr[p][c[i]];
	}
	return p;
}
int query1(){
	int p=1;
	for(int i=1;i<=cnt;i++){
		if(!tr[p][c[i]]) return 0;
		p=tr[p][c[i]];
	}
	return p;
}
int query(int p,int sz){
	int len=b[p].size(),ans=0;
	for(int i=0;i<len;i++){
		int pos=b[p][i].len;
		if(pos<=sz&&f[pos][0]==b[p][i].hsh1&&f[pos][1]==b[p][i].hsh2) ans+=b[p][i].cnt;
	}
	for(int i=1;i<=cnt;i++){
		if(!tr[p][c[i]]) return ans;
		p=tr[p][c[i]];
		len=b[p].size();
		for(int j=0;j<len;j++){
			int pos=b[p][j].len;
			if(pos<=sz&&f[pos][0]==b[p][j].hsh1&&f[pos][1]==b[p][j].hsh2) ans+=b[p][j].cnt;
		}
	}
	return ans;
}
int check(string ss){
	int nn=ss.size(),tt=0;
	for(int i=0;i<nn;i++){
		if(ss[i]!='a'&&ss[i]!='b') return 0;
		if(ss[i]!='a') tt++;
	}
	if(tt==1) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		int len=s.size();
		//if(!check(s)||!check(t)) T=1;
		int l=0,r=len-1;
		while(l<len&&s[l]==t[l]) l++;
		while(r>=0&&s[r]==t[r]) r--;
		cnt=0;
		for(int j=l;j<=r;j++) cnt++,c[cnt]=s[j]-'a';
		cnt++,c[cnt]=26;
		for(int j=l;j<=r;j++) cnt++,c[cnt]=t[j]-'a';
		cnt++,c[cnt]=26;
		for(int j=l-1;j>=0;j--) cnt++,c[cnt]=s[j]-'a';
		int p=insert();
		ull hsh1=0,hsh2=0;
		for(int j=r+1;j<len;j++){
			hsh1=(hsh1*101%MOD+s[j]-'a'+1)%MOD,hsh2=hsh2*37+s[j]-'a'+5;
		}
		int nn=b[p].size();
		if(nn&&b[p][nn-1].len==len-r-1&&b[p][nn-1].hsh1==hsh1&&b[p][nn-1].hsh2==hsh2){
			b[p][nn-1].cnt++;
		}
		else b[p].push_back((A){len-r-1,1,hsh1,hsh2});
	}
	for(int i=1;i<=m;i++){
		cin>>s>>t;if(s.size()!=t.size()){cout<<"0\n";continue;}
		int len=s.size();
		int l=0,r=len-1;
		while(l<len&&s[l]==t[l]) l++;
		while(r>=0&&s[r]==t[r]) r--;
		cnt=0;
		for(int j=l;j<=r;j++) cnt++,c[cnt]=s[j]-'a';
		cnt++,c[cnt]=26;
		for(int j=l;j<=r;j++) cnt++,c[cnt]=t[j]-'a';
		cnt++,c[cnt]=26;
		int p=query1();cnt=0;
		if(!p){cout<<"0\n";continue;}
		for(int j=l-1;j>=0;j--) cnt++,c[cnt]=s[j]-'a';
		ull hsh1=0,hsh2=0;
		for(int j=r+1;j<len;j++){
			hsh1=(hsh1*101%MOD+s[j]-'a'+1)%MOD,hsh2=hsh2*37+s[j]-'a'+5;
			f[j-r][0]=hsh1,f[j-r][1]=hsh2;
		}
		cout<<query(p,len-r-1)<<"\n";
	}
	return 0;
}
