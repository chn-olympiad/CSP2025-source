#include<bits/stdc++.h>
#define f(i,a,b) for(ll i=a;i<=b;i++)
typedef long long ll;
using namespace std;
ll n,m,k,a,b,c,cnt,sum,ar[20][15000];
ll f[15000],cn[15000],s[20],mi[15000],smi[15000];
pair<ll,pair<ll,ll> >edge[2500000];
vector<pair<ll,ll> >v[15000];
vector<ll>ad[20];
int find(ll a){
	return (f[a]==a?a:f[a]=find(f[a]));
}
void merge(ll x,ll y,ll v){
	if(find(x)!=find(y)){
		if(x>n)ad[x-n].push_back(y);
		if(y>n)ad[y-n].push_back(x);
		cn[x]++;cn[y]++;
		f[find(y)]=find(x);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	f(i,1,n+k)f[i]=i,mi[i]=smi[i]=LLONG_MAX;
	f(i,1,m){
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
		if(mi[a]>=c){
			smi[a]=mi[a];
			mi[a]=c;
		}else{
			smi[a]=min(smi[a],c);
		}
		if(mi[b]>=c){
			smi[b]=mi[b];
			mi[b]=c;
		}else{
			smi[b]=min(smi[b],c);
		}
		edge[++cnt]={c,{a,b}};
	}
	f(i,1,k){
		cin>>ar[i][0];
		f(j,1,n){
			cin>>ar[i][j];
			a=n+i,b=j,c=ar[i][j];
			v[a].push_back({b,c});
			v[b].push_back({a,c});
			if(mi[a]>=c){
				smi[a]=mi[a];
				mi[a]=c;
			}else{
				smi[a]=min(smi[a],c);
			}
			if(mi[b]>=c){
				smi[b]=mi[b];
				mi[b]=c;
			}else{
				smi[b]=min(smi[b],c);
			}//cout<<c<<" "<<a<<" "<<b<<endl;
			edge[++cnt]={c,{a,b}};
		}
	}
	sort(edge+1,edge+cnt+1);
	f(i,1,cnt){
		if(find(edge[i].second.first)==find(edge[i].second.second))continue;
		//cout<<edge[i].first<<" "<<edge[i].second.first<<" "<<edge[i].second.second<<endl;
		sum+=edge[i].first;
		merge(edge[i].second.first,edge[i].second.second,edge[i].first);
	}
	f(i,1,k){
		if(cn[n+i]==1){
			sum-=s[i];
		}
		else{
			int su=0,sn=0;
			for(auto j:ad[i]){
				sn+=ar[i][j];
				if(ar[i][j]==mi[j])su+=smi[j];
				else su+=mi[j];
			}//cout<<sn<<endl;
			sum=min(sum+ar[i][0],sum-sn+su);
		}
	}cout<<sum;
	//f(i,1,n+k)cout<<s[i];
}
