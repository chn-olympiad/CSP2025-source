#include <bits/stdc++.h>
#define N 200010
using namespace std;
int n,q;
string s1[N],s2[N],t1[N],t2[N];
int ans[N],len[N];
int tot=0;
map<int,int> mp;
vector<int> dis[N];
vector<int> nxt[N],nxt2[N];
int vis[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;int cnt1=0,cnt2=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
		for(int j=1;j<s1[i].size();j++){
			if(s1[i][j]!='a'&&s1[i][j]!='b') f=0;
			if(s2[i][j]!='a'&&s2[i][j]!='b') f=0;
			if(s1[i][j]=='b') cnt1++;
			if(s2[i][j]=='b') cnt2++;
		}
	}
	if(cnt1!=1||cnt2!=1) f=0;
	cnt1=0,cnt2=0;
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		t1[i]=' '+t1[i];
		t2[i]=' '+t2[i];
		if(t1[i].size()!=t2[i].size()){
			ans[i]=-1;
			continue;
		}
		for(int j=1;j<t1[i].size();j++){
			if(t1[i][j]!='a'&&t1[i][j]!='b') f=0;
			if(t2[i][j]!='a'&&t2[i][j]!='b') f=0;
			if(t1[i][j]=='b') cnt1++;
			if(t2[i][j]=='b') cnt2++;
		}
	}
	if(cnt1!=1||cnt2!=1) f=0;
	
	if(f){
		int d1=0,d2=0;
		for(int i=1;i<=n;i++){
			d1=0,d2=0;
			for(int j=1;j<s1[i].size();j++){
				if(s1[j][j]=='b') d1=j;
				if(s2[j][j]=='b') d2=j;
			}
			int tmp=d1-d2;
			if(mp.count(tmp)==0){
				mp[tmp]=++tot;
			}
			dis[mp[tmp]].push_back(d1);
		}
		for(int i=1;i<=q;i++){
			d1=0,d2=0;
			if(t1[i].size()!=t2[i].size()){
				cout<<0<<'\n';
				continue;
			}
			for(int j=1;j<t1[i].size();j++){
				if(t1[i][j]=='b') d1=j;
				if(t2[i][j]=='b') d2=j;
			}
			int tmp=d1-d2;
			if(mp.count(tmp)==0){
				cout<<0<<'\n';
				continue;
			}
			tmp=mp[tmp];
			int ans=upper_bound(dis[tmp].begin(),dis[tmp].end(),d1)-dis[tmp].begin();
			cout<<ans<<'\n';
		}
	}
	else{
		for(int i=1;i<=q;i++){
			int ans=0;
			int len1=t1[i].size()-1,len2=t2[i].size()-1;
			if(len1!=len2){
				cout<<0<<'\n';continue;
			}
			int mx=2e9,mn=-1;
			for(int j=1;j<=len1;j++){
				if(t1[i][j]!=t2[i][j]){
					mx=max(mx,j);
					mn=min(mn,j);
				}
			}
			
			for(int k=1;k<=n;k++){
				for(int j=1;j<=len1;j++){
					int tmp=t1[k].size()-1;
					bool tg=1;
					for(int p=1;p<=tmp;p++){
						if(s1[k][p]!=t1[i][j+p-1]) tg=0;
						if(s2[k][p]!=t2[i][j+p-1]) tg=0;
					}
					if(tg==1&&j<=mn&&(j+tmp)>=mx) ans++;
				}
			}
			cout<<ans<<'\n';
		}		
	}
	return 0;
}
	/*for(int i=1;i<=n;i++){
			nxt[i].push_back(0);
			for(int j=1;j<=s1[i].size();j++){
				nxt[i].push_back(0);
			}
			nxt[i][1]=0;
			int t=0;
			for(int j=2;j<=s1[i].size();j++){
				while(t&&s1[i][t+1]!=s1[i][j]) t=nxt[i][t];
				if(s1[i][t+1]==s1[i][j]) t++;
				nxt[i][j]=t;
			}
			
			nxt2[i].push_back(0);
			for(int j=1;j<=s2[i].size();j++){
				nxt2[i].push_back(0);
			}
			nxt2[i][1]=0;
			int t=0;
			for(int j=2;j<=s2[i].size();j++){
				while(t&&s2[i][t+1]!=s2[i][j]) t=nxt2[i][t];
				if(s2[i][t+1]==s2[i][j]) t++;
				nxt2[i][j]=t;
			}
		}*/
