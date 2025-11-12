#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,tot,cnt,a[200010],b[200010],ans[200010],vis[200010];
const int Base=37,Base2=1e6,mod=998244353;
vector<int> f1[200010],f2[200010],v2[200010],v3[200010],v4[200010];
vector<pair<int,int> > v[200010];
map<pair<int,int>,int > mp; 
signed main(){
//	system("fc replace.out replace4.ans"); return 0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s1,s2;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int x=0,y=s1.size()-1,w1=0,w2=0;
		while(x<=y && s1[x]==s2[x]) x++;
		if(x>y){
			i--;
			n--;
			continue;
		}
		while(x<=y && s1[y]==s2[y]) y--;
		for(int j=x;j<=y;j++){
			w1=(w1*Base+(s1[j]-'a'+1))%mod;
			w2=(w2*Base+(s2[j]-'a'+1))%mod;
		}
		if(!mp[make_pair(w1,w2)]) mp[make_pair(w1,w2)]=++tot;
		int p=mp[make_pair(w1,w2)];
		w1=w2=0;
		for(int j=x-1;j>=0;j--) w1=(w1*Base+(s1[j]-'a'+1))%mod;
		for(int j=y+1;j<s1.size();j++) w2=(w2*Base+(s1[j]-'a'+1))%mod;
		v[p].push_back(make_pair(w1,w2));
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			ans[i]=0;
			continue;
		}
		int x=0,y=s1.size()-1,w1=0,w2=0;
		while(x<=y && s1[x]==s2[x]) x++;
		while(x<=y && s1[y]==s2[y]) y--;
		for(int j=x;j<=y;j++){
			w1=(w1*Base+(s1[j]-'a'+1))%mod;
			w2=(w2*Base+(s2[j]-'a'+1))%mod;
		}
		if(!mp[make_pair(w1,w2)]){
			ans[i]=0;
			continue;
		}
		int p=mp[make_pair(w1,w2)];
		w1=w2=0;
		f1[i].push_back(0);
		f2[i].push_back(0);
		for(int j=x-1;j>=0;j--){
			w1=(w1*Base+(s1[j]-'a'+1))%mod;
			f1[i].push_back(w1);
		}
		for(int j=y+1;j<s1.size();j++){
			w2=(w2*Base+(s1[j]-'a'+1))%mod;
			f2[i].push_back(w2);
		}
		v2[p].push_back(i);
	}
	for(int i=1;i<=tot;i++){
		if(!v2[i].size()) continue;
		cnt=0;
		for(int j=0;j<v[i].size();j++){
			a[++cnt]=v[i][j].first;
			b[cnt]=v[i][j].second;
		}
		sort(a+1,a+cnt+1);
		sort(b+1,b+cnt+1);
		for(int j=0;j<v[i].size();j++){
			v[i][j].first=lower_bound(a+1,a+cnt+1,v[i][j].first)-a;
			v[i][j].second=lower_bound(b+1,b+cnt+1,v[i][j].second)-b;
			v3[v[i][j].first].push_back(v[i][j].second);
		}
		int B=sqrt(cnt)+1;
		for(auto x:v2[i]){
			for(int j=0;j<f1[x].size();j++){
				int p=lower_bound(a+1,a+cnt+1,f1[x][j])-a;
				if(a[p]!=f1[x][j]) f1[x][j]=0;
				else f1[x][j]=p;
			}
			for(int j=0;j<f2[x].size();j++){
				int p=lower_bound(b+1,b+cnt+1,f2[x][j])-b;
				if(b[p]!=f2[x][j]) f2[x][j]=0;
				else f2[x][j]=p;
			}
			sort(f1[x].begin(),f1[x].end());
			f1[x].erase(unique(f1[x].begin(),f1[x].end()),f1[x].end());
			sort(f2[x].begin(),f2[x].end());
			f2[x].erase(unique(f2[x].begin(),f2[x].end()),f2[x].end());
		}
		for(auto x:v2[i]){
			for(int j=0;j<f2[x].size();j++) vis[f2[x][j]]=1;
			for(int j=0;j<f1[x].size();j++){
				int w=f1[x][j];
				if(v3[w].size()<=B || q==1){
					for(auto y:v3[w]) if(vis[y]) ans[x]++;
				}else v4[w].push_back(x);
			}
			for(int j=0;j<f2[x].size();j++) vis[f2[x][j]]=0;
		}
		for(int j=1;j<=cnt;j++){
			if(v3[j].size()<=B || !v4[j].size()) continue;
			for(auto x:v3[j]) vis[x]++;
			for(auto x:v4[j]) for(auto y:f2[x]) ans[x]+=vis[y];
			for(auto x:v3[j]) vis[x]=0;
			v4[j].clear();
		}
		for(int j=0;j<v[i].size();j++) v3[v[i][j].first].clear();
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}
