/*
东拼西凑大概能得个前六的点的 30pts 吧 
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10,mod=998244853;

int n,q,l[N],r[N],h[N][2],ht[N*30][2],mi[N*30],la[N][2],ra[N][2];
vector<char> s[N][2],t[2];

int cal(int l,int r,int tp){
	return (ht[r][tp]-1ll*mi[r-l+1]*ht[l-1][tp]%mod+mod)%mod;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	bool flag=1;
	mi[0]=1;
	for(int i=1;i<=5e6;i++)
		mi[i]=1ll*mi[i-1]*31%mod;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch<'a' || 'z'<ch) ch=getchar();
		while('a'<=ch && ch<='z') s[i][0].emplace_back(ch),ch=getchar();
		while(ch<'a' || 'z'<ch) ch=getchar();
		while('a'<=ch && ch<='z') s[i][1].emplace_back(ch),ch=getchar();
		while(l[i]<s[i][0].size() && s[i][0][l[i]]==s[i][1][l[i]]) l[i]++;
		while(r[i]<s[i][0].size() && s[i][0][s[i][0].size()-r[i]-1]==s[i][1][s[i][1].size()-r[i]-1]) r[i]++;
		for(int j=0;j<s[i][0].size();j++)
			h[i][0]=(h[i][0]*31ll+s[i][0][j]-'a')%mod;
		for(int j=0;j<s[i][1].size();j++)
			h[i][1]=(h[i][1]*31ll+s[i][1][j]-'a')%mod;
		if(flag){
			int bb=0;
			for(char j:s[i][0]){
				if(j=='b')
					bb++;
				else if(j!='a')
					flag=0;
			}
			if(bb!=1)
				flag=0;
			bb=0;
			for(char j:s[i][1]){
				if(j=='b')
					bb++;
				else if(j!='a')
					flag=0;
			}
			if(bb!=1)
				flag=0;
		}
		if(flag){
			for(int j=0;j<s[i][0].size();j++)
				if(s[i][0][j]=='b'){
					la[i][0]=j,ra[i][0]=s[i][0].size()-j-1;
					break;
				}
			for(int j=0;j<s[i][1].size();j++)
				if(s[i][1][j]=='b'){
					la[i][1]=j,ra[i][1]=s[i][1].size()-j-1;
					break;
				}
		}
	}
	while(q--){
		char ch=getchar();
		t[0].clear();
		t[1].clear();
		while(ch<'a' || 'z'<ch) ch=getchar();
		while('a'<=ch && ch<='z') t[0].emplace_back(ch),ch=getchar();
		while(ch<'a' || 'z'<ch) ch=getchar();
		while('a'<=ch && ch<='z') t[1].emplace_back(ch),ch=getchar();
		int lt=0,rt=0;
		long long ans=0;
		while(lt<t[0].size() && t[0][lt]==t[1][lt]) lt++;
		while(rt<t[0].size() && t[0][t[0].size()-rt-1]==t[1][t[1].size()-rt-1]) rt++;
		for(int i=0;i<t[0].size();i++){
			if(!i) ht[i][0]=t[0][i]-'a';
			else ht[i][0]=(1ll*ht[i-1][0]*31+t[0][i]-'a')%mod;
		}
		for(int i=0;i<t[1].size();i++){
			if(!i) ht[i][1]=t[1][i]-'a';
			else ht[i][1]=(1ll*ht[i-1][1]*31+t[1][i]-'a')%mod;
		}
		int bb[2]={0,0},ff=1;
		for(char j:t[0]){
			if(j=='b')
				bb[0]++;
			else if(j!='a')
				ff=0;
		}
		for(char j:t[1]){
			if(j=='b')
				bb[1]++;
			else if(j!='a')
				ff=0;
		}
		if(flag && bb[0]==1 && bb[1]==1 && ff){
			int tla[2]={0,0},tra[2]={0,0};
			for(int i=0;i<t[0].size();i++)
				if(t[0][i]=='b'){
					tla[0]=i,tra[0]=t[0].size()-i-1;
					break;
				}
			for(int i=0;i<t[1].size();i++)
				if(t[1][i]=='b'){
					tla[1]=i,tra[1]=t[1].size()-i-1;
					break;
				}
			for(int i=1;i<=n;i++)
				if(tla[0]>=la[i][0] && tla[0]-la[i][0]+la[i][1]==tla[1] && tra[0]>=ra[i][0] && tra[0]-ra[i][0]+ra[i][1]==tra[1])
					ans++;
		}else if(lt<t[0].size()){
			for(int i=1;i<=n;i++){
				if(l[i]==s[i][0].size() || l[i]>lt || r[i]>rt)
					continue;
				if(cal(lt-l[i],t[0].size()-rt-1+r[i],0)==h[i][0] && cal(lt-l[i],t[0].size()-rt-1+r[i],1)==h[i][1])
					ans++;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(h[i][0]!=h[i][1])
					continue;
				for(int j=0;j+s[i][0].size()<=t[0].size();j++)
					if(h[i][0]==cal(j,j+s[i][0].size()-1,0))
						ans++;
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
/*
3 1
aba aba
ab ca
ddd dcd
abcdddabc abcdddabc
*/
