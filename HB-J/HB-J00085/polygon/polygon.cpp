#include<bits/stdc++.h>
#define LL long long

using namespace std;

const LL N=5010,MOD=998244353;
LL n,a[N],ans=0;

bool cmp(LL a,LL b){
	return a<b;
}

map<LL,LL>mp;
vector<LL>v,r;

void add(int v,int q){
	//printf("add %lld %lld\n",v,q);
	if(mp.find(v)==mp.end()){
		mp[v]=q;
	}else{
		mp[v]+=q;
	}
	mp[v]=mp[v]%MOD;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int x=1;x<=n;x++){
		scanf("%lld",&a[x]);
	}
	sort(a+1,a+n+1,cmp);
	for(int x=1;x<=n;x++){
		//printf("check %d------\n",a[x]);
		v.clear();
		r.clear();
		if(x>=3){
			for(auto it=mp.begin();it!=mp.end();it++){
				v.push_back(it->first);
				r.push_back(it->second);
				if((it->first)>a[x]){
					//printf("%lld %lld\n",it->first,it->second);
					ans=(ans+it->second)%MOD;
				}
			}
			for(int c=0;c<v.size();c++){
				add(v[c]+a[x],r[c]);
			}
			add(a[x],1);
		}else{
			for(auto it=mp.begin();it!=mp.end();it++){
				v.push_back(it->first);
				r.push_back(it->second);
			}
			for(int c=0;c<v.size();c++){
				add(v[c]+a[x],r[c]);
			}
			add(a[x],1);
		}
	}
	cout<<ans;
	return 0;
}
/*
5
2 2 3 8 10
5
1 2 3 4 5
*/

