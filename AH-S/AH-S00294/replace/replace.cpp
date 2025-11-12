#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
const int N=200005;
int n,q,len[N],cnt,flag[N];
vector<int> nxt[N];
vector<ull> t1[N],t2[N];
unsigned long long hsh[N],pp[N];
string from[N],to[N];
void getnxt(string s,int op,int n){
	int j=0;nxt[op][1]=0;
	for(int i=2;i<=n;++i){
		while(j&&s[j+1]!=s[i])j=nxt[op][j];
		if(s[j+1]==s[i])++j;
		nxt[op][i]=j;
	}
}
vector<int> ans;
void KMP(string s,string t,int op,int n,int m){
	int j=0;
	for(int i=1;i<=m;++i){
		while(j&&s[j+1]!=t[i])j=nxt[op][j];
		if(s[j+1]==t[i])++j;
		if(j==n){ans.push_back(i);j=nxt[op][j];}
	}
}
ull tmp2[N];
int step[5],flag1=1;
map<int,int> Cnt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;pp[0]=1;
	for(int i=1;i<=n;++i)pp[i]=pp[i-1]*26ll;
	string s1,s2;
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
		int l=s1.size();
		from[i]=to[i]=" ";
		from[i]+=s1,to[i]+=s2;
		len[i]=l;
		nxt[i].resize(l+5);
		t1[i].resize(l+5);
		t2[i].resize(l+5);t1[i][0]=t2[i][0]=0;
		for(int j=1;j<=l;++j)t1[i][j]=t1[i][j-1]*26+from[i][j]-'a';
		step[1]=step[0]=0;
		for(int j=1;j<=l;++j){
			if(from[i][j]=='a'||from[i][j]=='b')++step[from[i][j]-'a'];
			else flag1=0;
		}
		if(step[1]!=1)flag1=0;step[1]=step[0]=0;
		for(int j=1;j<=l;++j){
			if(to[i][j]=='a'||to[i][j]=='b')++step[to[i][j]-'a'];
			else flag1=0;
		}
		if(step[1]!=1)flag1=0;
		if(flag1){
			int pos1,pos2;
			for(int j=1;j<=l;++j){
				if(from[i][j]=='b'){
					pos1=j;
					break;
				}
			}
			for(int j=1;j<=l;++j){
				if(to[i][j]=='b'){
					pos2=j;
					break;
				}
			}
			++Cnt[pos2-pos1];
		}
		for(int j=1;j<=l;++j)t2[i][j]=t2[i][j-1]*26+to[i][j]-'a';
		getnxt(from[i],i,l);
		// cout<<t1[i][l]<<' ';
		// for(int j=1;j<=l;++j)cout<<nxt[i][j]<<' ';
		// cout<<'\n';
	}
	// if(flag1)exit(1);
	// if(q==1){
		string s3,s4;
		for(int i=1;i<=q;++i){
			cnt=0;
			cin>>s1>>s2;
			int l=s1.size();
			s3=" ";s3+=s1;
			s4=" ";s4+=s2;
			int L=0,R=0,fl=1;
			step[1]=step[0]=0;
			for(int i=1;i<=l;++i){
				if(s3[i]=='a'||s3[i]=='b')++step[s3[i]-'a'];
				else fl=0;
			}
			if(step[1]!=1)fl=0;
			step[1]=step[0]=0;
			for(int i=1;i<=l;++i){
				if(s4[i]=='a'||s4[i]=='b')++step[s4[i]-'a'];
				else fl=0;
			}
			if(step[1]!=1)fl=0;
			if(flag1&&fl){
				int pos1,pos2;
				for(int j=1;j<=l;++j){
					if(s3[j]=='b'){
						pos1=j;
						break;
					}
				}
				for(int j=1;j<=l;++j){
					if(s4[j]=='b'){
						pos2=j;
						break;
					}
				}
				cout<<Cnt[pos2-pos1]<<'\n';
				// if(fl)exit(1);
				continue;
			}			
			for(int i=1;i<=l;++i){
				if(s3[i]!=s4[i]){if(!L)L=i;flag[i]=1;R=i;}
				else flag[i]=0;
			}
			// for(int i=1;i<=l;++i)tmp1=tmp1*26+s3[i]-'a';
			for(int i=1;i<=l;++i)tmp2[i]=tmp2[i-1]*26+s4[i]-'a';
			int siz=R-L+1;
			for(int j=1;j<=n;++j){
				if(len[j]<siz)continue;
				if(len[j]>l)continue;
				KMP(from[j],s3,j,len[j],l);
				if(ans.empty())continue;
				// cout<<j<<'\n';
				for(int pos:ans){
					int st=pos-len[j]+1;
					int ed=pos;
					if(st<=L&&ed>=R){
						// cout<<"st ed:"<<st<<' '<<ed<<'\n';
						// cout<<"L R:"<<L<<' '<<R<<'\n';
						// ed=R-st+1;st=L-st+1;
						// cout<<L<<' '<<R; 
						// if(ed>l){ans.clear();continue;}
						ull v1=tmp2[ed]-tmp2[st-1]*pp[ed-st+1];
						// cout<<"\nCompare:"<<v1<<' '<<tmp2<<'\n';
						// cout<<"\n"<<st<<' '<<ed<<'\n';
						if(v1==t2[j][len[j]]){
							// cout<<"find:"<<j<<'\n';
							++cnt;
							// cout<<"id:"<<j<<'\n';
							// cout<<"string:"<<from[j]<<' '<<to[j]<<'\n';
							// cout<<"L R:"<<L<<' '<<R<<'\n';
							// cout<<"st ed:"<<st<<' '<<ed<<'\n';
						}
					}
				}
				ans.clear();
			}
			// cout<<L<<' '<<R<<'\n';
			// cout<<"cnt:"<<cnt<<'\n'<<'\n';
			cout<<cnt<<'\n';
		}
		// return 0;
	// }
	return 0;
}