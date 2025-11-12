#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int N=2e5+5,M=5e6+5;
int n,m;
string S[N],T[N],s,t;
int len[N];
ull Sh[N],Th[N],Bas=137,sh[M],th[M],p[M];
int pian[N],ls[N],rs[N];
map<int,int> mp;
int tot=0;
vector <pair<int,int> > re[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n<=100){
		for(int i=1;i<=n;i++){
			cin>>S[i]>>T[i];
			len[i]=S[i].length();
			for(int j=0;j<len[i];j++){
				Sh[i]=Sh[i]*Bas+S[i][j]-'a'+1;
				Th[i]=Th[i]*Bas+T[i][j]-'a'+1;
			}
		}
		p[0]=1;
		for(int i=1;i<=5e6;i++) p[i]=p[i-1]*Bas;
		for(int i=1;i<=m;i++){
			cin>>s>>t;
			int l=s.length(),sl,sr;
			for(int j=0;j<l;j++){
				sh[j]=sh[j-1]*Bas+s[j]-'a'+1;
				th[j]=th[j-1]*Bas+t[j]-'a'+1;
			}
			for(int j=0;j<l;j++){
				if(s[j]!=t[j]){
					sl=j;
					break;
				}
			}
			ll ans=0;
			for(int j=l-1;j>=0;j--){
				if(s[j]!=t[j]){
					sr=j;
					break;
				}
			}
			for(int j=0;j<=sl;j++){
				for(int k=1;k<=n;k++){
					if(len[k]<sr-j+1) continue;
					if(len[k]>l-1-j+1) continue;
					if(Sh[k]==sh[j+len[k]-1]-(j>0?sh[j-1]:0)*p[len[k]]&&Th[k]==th[j+len[k]-1]-(j>0?th[j-1]:0)*p[len[k]]) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		char ch=getchar();int l=0,p1,p2;
		while(ch<'a'||ch>'z') ch=getchar();
		while(ch>='a'&&ch<='z'){
			l++;
			if(ch=='b') p1=l;
			ch=getchar();
		}
		while(ch<'a'||ch>'z') ch=getchar();
		while(ch>='a'&&ch<='z'){
			if(ch=='b') p2=l;
			ch=getchar();
		}
		pian[i]=p2-p1;ls[i]=p1,rs[i]=l-p2+1;
		if(!mp[pian[i]]) mp[pian[i]]=++tot;
		re[mp[pian[i]]].push_back({ls[i],rs[i]});
	}
	for(int i=1;i<=m;i++){
		char ch=getchar();int l=0,p1,p2,pi,pl,pr,res=0;
		while(ch<'a'||ch>'z') ch=getchar();
		while(ch>='a'&&ch<='z'){
			l++;
			if(ch=='b') p1=l;
			ch=getchar();
		}
		while(ch<'a'||ch>'z') ch=getchar();
		while(ch>='a'&&ch<='z'){
			if(ch=='b') p2=l;
			ch=getchar();
		}
		pi=p2-p1,pl=p1,pr=l-p2+1;
		if(!mp[pi]){
			cout<<"0\n";
			continue;
		}
		int to=mp[pi];
		for(int j=0;j<re[to].size();j++){
			if(re[to][j].fi<=pl&&re[to][j].se<=pr) res++;
		}
		cout<<res<<'\n';
		continue;
	}
	return 0;
}