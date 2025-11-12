#include<bits/stdc++.h>
using namespace std;
int n,m,lens[200005],tot[200005];
long long pw0[2000005],pw1[2000005];
string s0[200005],s1[200005];
const int mod0=1e9+7,mod1=998244353;
vector<int> hx0[200005],hx1[200005];
map<int,set<int> > mp0,mp1;
map<int,bool> vis0,vis1;
int suan0(int l,int r){
	//cout<<"S:"<<hx0[n+1][r]<<" "<<hx0[n+1][l-1]<<" "<<pw0[r-l+1]<<"\n";
	return (hx0[n+1][r]-1ll*hx0[n+1][l-1]*pw0[r-l+1]%mod0+mod0)%mod0;
}
int suan1(int l,int r){
	return (hx1[n+1][r]-1ll*hx1[n+1][l-1]*pw1[r-l+1]%mod1+mod1)%mod1;
}
int zhao(int L,int R){
	int l=L,r=R,tmp=0;
	//cout<<"ZHAO:"<<L<<" "<<R<<" "<<"\n";
	while(l<=r){
		int mid=l+r>>1;
		//cout<<l<<" "<<r<<" "<<mid<<"\n";
		if(vis0[suan0(L,mid)]&&vis1[suan1(L,mid)]){
			l=mid+1;
			tmp=mid;
		}
		else r=mid-1;
	}
	int tmps=suan0(L,tmp);
	int sum=0;
	//cout<<tmp<<" "<<tmps<<"\n";
	for(auto it:mp0[tmps]){
		if(hx1[it][lens[it]-1]==suan1(L,tmp)){
			return tot[it];
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	pw0[0]=pw1[0]=1;
	for(int i=1;i<=2000000;++i) pw0[i]=pw0[i-1]*27%mod0,pw1[i]=pw1[i-1]*27%mod1;
	for(int i=1;i<=n;++i){
		cin>>s0[i]>>s1[i];
		lens[i]=s0[i].size();
		for(int j=0;j<lens[i];++j){
			hx0[i].push_back(s0[i][j]-'a'+1);
			hx1[i].push_back(s1[i][j]-'a'+1);
			if(j){
				hx0[i][j]=(hx0[i][j]+1ll*27*hx0[i][j-1]%mod0)%mod0;
				hx1[i][j]=(hx1[i][j]+1ll*27*hx1[i][j-1]%mod1)%mod1;
			}
			vis0[hx0[i][j]]=vis1[hx1[i][j]]=1;
		}
		mp0[hx0[i][lens[i]-1]].insert(i);
		mp1[hx1[i][lens[i]-1]].insert(i);
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<s0[i].size();++j){
			for(auto it:mp0[hx0[i][j]]){
				if(mp1[hx1[i][j]].count(it)){
					tot[i]++;
				}
			}
		}
	//	cout<<"I&TOT:"<<i<<" "<<tot[i]<<" "<<hx0[i][lens[i]-1]<<" "<<hx1[i][lens[i]-1]<<"\n";
	}
	while(m--){
		string q0,q1;
		cin>>q0>>q1;
		if(q0.size()!=q1.size()){
			cout<<"0\n";
			continue;
		}
		int tmp=q0.size(),wz=tmp;
		hx0[n+1].clear(),hx1[n+1].clear();
		for(int j=0;j<tmp;++j){
			hx0[n+1].push_back(q0[j]-'a');
			hx1[n+1].push_back(q1[j]-'a');
			if(j){
				hx0[n+1][j]=(hx0[n+1][j]+1ll*27*hx0[n+1][j-1]%mod0)%mod0;
				hx1[n+1][j]=(hx1[n+1][j]+1ll*27*hx1[n+1][j-1]%mod1)%mod1;
			}
		//	cout<<"j:"<<j<<" "<<hx0[n+1][j]<<"\n";
		}
		for(int i=tmp-1;i;--i){
			if(q0[i]!=q1[i]) break;
			wz=i;
		}
	//	cout<<wz<<" "<<zhao(1,wz)<<"\n";
		long long ans=0;
		for(int i=0;i<tmp;++i){
			ans+=zhao(i,n)-zhao(i,wz-2);
		//	cout<<"IZ:"<<i<<" "<<zhao(i,n)<<" "<<zhao(i,wz-2)<<"\n";
			if(q0[i]!=q1[i]) break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}