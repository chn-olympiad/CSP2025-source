#include<bits/stdc++.h>
#define int long long
#define pss pair<string,string>
#define pii pair<int,int>
using namespace std;
const int sft=5000000;
string a[500007],b[500007];
unordered_map<string,vector<pss>> mp; 
vector<pii> xc[10000007];
int n,Q;
int cnt[107];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i].size();++j){
			cnt[a[i][j]-'a']++;
		}
	}
	int f=1;
	for(int i=2;i<=26;++i){
		if(cnt[i]!=0){
			f=0;
			break;
		}
	}
	if(cnt[1]!=n) f=0;
	if(f){
		for(int i=1;i<=n;++i){
			int ss=a[i].size(),ta=0,tb=0;
			for(int j=0;j<ss;++j){
				if(a[i][j]=='b'){
					ta=j;
					break;
				}
			}
			for(int j=0;j<ss;++j){
				if(b[i][j]=='b'){
					tb=j;
					break;
				}
			}
			xc[ta-tb+sft].push_back({ta,ss-tb-1});
		}
		for(int q=1;q<=Q;++q){
			string x,y;
			cin>>x>>y;
			int txx=0,tyy=0,xs=x.size(),ys=y.size(),ans=0;
			for(int j=xs-1;j>=0;--j){
				if(x[j]=='b'){
					txx=j;
					break;
				}
			}
			for(int j=ys-1;j>=0;--j){
				if(y[j]=='b'){
					tyy=j;
					break;
				}
			}
			for(int i=0;i<xc[txx-tyy+sft].size();++i){
				if(txx>=xc[txx-tyy+sft][i].first&&ys-tyy-1>=xc[txx-tyy+sft][i].second) ans++;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		int c=0;
		for(int j=a[i].size()-1;j>=0;--j){
			if(a[i][j]!=b[i][j]) break;
			c++;
		}
		mp[a[i].substr(0,a[i].size()-c)].push_back({a[i],b[i]});
	}
	for(int q=1;q<=Q;++q){
		string x,y;
		cin>>x>>y;
		int c=0,d=0,ans=0;
		for(int j=x.size()-1;j>=0;--j){
			if(x[j]!=y[j]) break;
			d++;
		}
		for(int j=0;j<x.size();++j){
			if(x[j]!=y[j]) break;
			c++;
		}
		for(int i=c;i>=0;--i){
			string s=x.substr(i,x.size()-d-i);
			for(int j=0;j<mp[s].size();++j){
				if(i+mp[s][j].first.size()-1>=x.size()) continue;
				if(x.substr(i,mp[s][j].first.size())==mp[s][j].first&&y.substr(i,mp[s][j].second.size())==mp[s][j].second){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
