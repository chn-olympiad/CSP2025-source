#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=2e5+5;
int n,q,cnt,LEN[N];
string s[N][5];
vector<int>kmp[N];
void getkmp(int x,int len){
	kmp[x].resize(len+2);
	string S=s[x][1];
	kmp[x][1]=0;
//	cout<<"!"<<S<<'\n';
	for(int i=2;i<=len;i++){
		int j=kmp[x][i-1];
		while(j&&S[j+1]!=S[i])j=kmp[x][j];
		if(S[j+1]==S[i])j++;
		kmp[x][i]=j;
	}
//	for(int i=1;i<=len;i++)cout<<kmp[x][i]<<" ";
//	cout<<'\n';
}
vector<int>g[N];
map<string,int>mp;
bool ck(int id,string t){
	int len=t.length();
	int j=0;
	for(int i=1;i<=len;i++){
		while(j&&s[id][1][j+1]!=t[i])j=kmp[id][j];
		if(s[id][1][j+1]==t[i])j++;
		if(j==LEN[id])return 1;
	}
	return 0;
}
void solve(){
	n=read();q=read();cnt=0;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int len=s[i][1].length();
		LEN[i]=len;
		s[i][1]='#'+s[i][1];
		s[i][2]='#'+s[i][2];
//		cout<<"?"<<s[i][1]<<" "<<s[i][2]<<'\n';
		int L=1,R=len;
		while(L<=len&&s[i][1][L]==s[i][2][L])L++;
		while(R>=1&&s[i][1][R]==s[i][2][R])R--;
//		cout<<"?"<<L<<" "<<R<<'\n';
		getkmp(i,len);
		if(L<=R){
			string S="";
			for(int p=L;p<=R;p++)S+=s[i][1][p];
			for(int p=L;p<=R;p++)S+=s[i][2][p];
			if(!mp.count(S))mp[S]=++cnt;
//			cerr<<"?"<<S<<" "<<mp[S]<<'\n';
			g[mp[S]].push_back(i);
		}
	}
	//cerr<<"?"<<mp.size()<<'\n';
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		t1='#'+t1;
		t2='#'+t2;
		if(t1.length()!=t2.length()){
			puts("0");continue;
		}
		int len=t1.length();
		int L=1,R=len;
		while(L<=len&&t1[L]==t2[L])L++;
		while(R>=1&&t1[R]==t2[R])R--;
		string S="";
		for(int i=L;i<=R;i++)S+=t1[i];
		for(int i=L;i<=R;i++)S+=t2[i];
		if(!mp.count(S)){
			puts("0");continue;
		}
		int id=mp[S],ans=0;
		for(int i=0;i<g[id].size();i++){
			int x=g[id][i];
			//cout<<"?"<<x<<'\n';
			if(ck(x,t1))ans++;
		}
		printf("%lld\n",ans);
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//freopen(".out","w",stdout);
	int T;T=1;while(T--)solve();
	//cerr<<1.0*clock()/CLOCKS_PER_SEC<<"ms"<<'\n';
	return 0;
}

