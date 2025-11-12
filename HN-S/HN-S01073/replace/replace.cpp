#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define oo
int n,m,ans;
string a[N],b[N];
vector<int>cnt[30];
int sum[30];
bool used[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}return x*f;
}
void write(int x){
	static int st[40],top=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	while(x){
		st[++top]=x%10;
		x/=10;
	}if(top==0) st[++top]=0;
	while(top) putchar(st[top--]);
	return ;
}
void solve(int pl,string l,string r){
	if(l==r) {
		ans++;return ;
	}
	if(pl>=l.size()) return ;
	int ned=l[pl]-'a';
	bool flag=0;
	if(sum[ned]!=0)
	for(auto i : cnt[ned]){
		if(used[i]) continue;
		int len=a[i].size(),lenb=b[i].size();
		if(l.substr(pl,len)!=a[i]) continue;
		used[i]=1;
		sum[ned]--;
		string l1=l.substr(0,pl)+b[i]+l.substr(pl+len,l.size()-pl-len);
		solve(pl+len,l1,r);
		used[i]=0;sum[ned]++;
	}
	solve(pl+1,l,r);
	return ;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt[a[i][0]-'a'].push_back(i);
		sum[a[i][0]-'a']++;
	}
	while(m--){
		string s,t;
		ans=0;
		cin>>s>>t;
		solve(0,s,t);
		cout<<ans<<endl;
	}return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex 
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
