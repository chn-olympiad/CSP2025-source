#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct xy{
	int fr,to;long long w;int m;
	bool operator<(const xy b)const{
		return w<b.w;
	}
};
vector<xy> e;
vector<long long> mw;
vector<bool> mus;
int sss[int(1e4+10)];
struct bcj{
	vector<int> pa,size;
	bcj(int n){
		pa.resize(n);
		for(int i=0;i<n;i++) pa[i]=i;
		size.resize(n);
	}
	bool uu(int a,int b){
		int aa=find(a),bb=find(b);
//		int aa=pa[a],bb=pa[b];
		if(aa==bb) return false;
		if(size[a]<size[b]){swap(aa,bb);swap(a,b);}
		pa[b]=aa;
		return true;
	}
	int find(int a){
		return pa[a]=(pa[a]==a?a:find(pa[a]));
	}
};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
//freopen("C:/Users/Administrator/Documents/problem/road/road.in","r",stdin);
	cin>>n>>m>>k;
	mw.resize(k);
	mus.resize(k);
	for(int i=0,u,v,x;i<m;i++){
		cin>>u>>v>>x;
		e.push_back({u,v,x,-1});
	}
	for(int kk=0;kk<k;kk++){
		long long ss;
		cin>>ss;
		for(int j=0;j<n;j++)
			cin>>sss[j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j) e.push_back({i,j,ss+sss[i]+sss[j],kk});
		mw[kk]=ss;
	}
	bcj jj(n+15);
	sort(e.begin(),e.end());
	long long ans=0;
	int sum=0;
	for(auto ee:e){
		if(jj.uu(ee.fr,ee.to)){
			sum++;
			if(ee.m!=-1){
				if(mus[ee.m])
					ans-=mw[ee.m];
				mus[ee.m]=true;
			}
			ans+=ee.w;
//			cout<<" > ";cout<<ee.fr<<" <-> "<<ee.to<<"  :"<<ee.w<<'\n';
			if(sum>=n-1) break;
		}
//		else cout<<ee.fr<<" <-> "<<ee.to<<"  :"<<ee.w<<'\n';
	}
	
	cout<<ans<<'\n';
	return 0;
}
