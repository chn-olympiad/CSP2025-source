#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ull unsigned long long
#define ll long long
#define jz 83
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
pair<string,string>pr[200010];
const int M=(1<<23)-1;
bitset<1<<23>vis1,vis2;
gp_hash_table<ull,int>mp[3010];
gp_hash_table<ull,null_type>mp1;
ull h[2500010],pw[5000010];
ull gt(int l,int r){return h[r]-h[l-1]*pw[2*(r-l+1)];}
vector<int>L;
int main(){
	fre("replace"),cin.tie(0)->sync_with_stdio(0);
	int n,q;cin>>n>>q,pw[0]=1;
	for(int i=1;i<=5e6;++i)pw[i]=pw[i-1]*jz;
	for(int i=1;i<=n;++i){
		cin>>pr[i].first>>pr[i].second;
		if(pr[i].first==pr[i].second)continue;
		L.push_back(pr[i].first.size());
	}
	sort(L.begin(),L.end()),L.erase(unique(L.begin(),L.end()),L.end());
	for(int i=1;i<=n;++i){
		if(pr[i].first==pr[i].second)continue;
		const int tmp=lower_bound(L.begin(),L.end(),pr[i].first.size())-L.begin();
		ull nwh=0,th=0,ansh=0;bool flg=0;
		for(int j=0;j<pr[i].first.size();++j){
			nwh=nwh*jz+pr[i].first[j];
			nwh=nwh*jz+pr[i].second[j];
			if(flg){
				th=th*jz+pr[i].first[j];
				th=th*jz+pr[i].second[j];
			}
			if(pr[i].first[j]!=pr[i].second[j]){
				if(!flg){
					flg=1,th=1;
					th=th*jz+pr[i].first[j];
					th=th*jz+pr[i].second[j];
				}
				ansh=th;
			}
		}
		++mp[tmp][nwh],vis1[nwh&M]=1,vis2[(nwh>>23)&M]=1,mp1.insert(ansh);
	}
	while(q--){
		string t1,t2;cin>>t1>>t2;
		ull th=0,ansh=0;bool flg=0;
		int st=0,ed=0;
		for(int j=0;j<t1.size();++j){
			if(flg){
				th=th*jz+t1[j];
				th=th*jz+t2[j];
			}
			if(t1[j]!=t2[j]){
				if(!flg){
					st=j;
					flg=1,th=1;
					th=th*jz+t1[j];
					th=th*jz+t2[j];
				}
				ed=j;
				ansh=th;
			}
			h[j+1]=h[j]*jz+t1[j],h[j+1]=h[j+1]*jz+t2[j];
		}
		if(mp1.find(ansh)==mp1.end()){cout<<"0\n";continue;}
		ll nwans=0;int cnt=0;
		for(auto k:L){
			if(k>t1.size())break;
			for(int i=max(0,ed-k+1);i<=st&&i+k<=t1.size();++i){
				ull nw=gt(i+1,i+k);
				if(vis1[nw&M]&&vis2[(nw>>23)&M]){
					auto it=mp[cnt].find(nw);
					if(it!=mp[cnt].end())nwans+=(*it).second;
				}
			}
			++cnt;
		}
		cout<<nwans<<'\n';
	}
	return 0;
}