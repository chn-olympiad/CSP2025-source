#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+7;

ll a[N][6],n,t[N],r,s[N],c[6],l[6];
vector<pair<ll,ll>> v;

bool vv(pair<ll,ll> x,pair<ll,ll> y){
	return max(x.first,x.second)>max(y.first,y.second);
}

void solve(){
	v.clear(); v.shrink_to_fit();
	scanf("%lld",&n); r=0;
	c[1]=0; c[2]=0; c[3]=0;
	
	for(int i=1;i<=n;i++){
		ll tt=0;
		for(int j=1;j<=3;j++) scanf("%lld",&a[i][j]),tt=max(tt,a[i][j]);
		for(int j=1;j<=3;j++){
			if(a[i][j]==tt){
				s[i]=j;
				c[j]++,r+=tt;
				break;
			}
		}
	}
	
	if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2){
		printf("%lld\n",r);
		return;
	}
	 
	
	if(c[2]>n/2){
		for(int i=1;i<=n;i++){
			swap(a[i][2],a[i][1]);
			if(s[i]==2) s[i]=1;
			else if(s[i]==1) s[i]=2;
		}
		swap(c[2],c[1]);
	}
	else if(c[3]>n/2){
		for(int i=1;i<=n;i++){
			swap(a[i][3],a[i][1]);
			if(s[i]==3) s[i]=1;
			else if(s[i]==1) s[i]=3;
		}
		swap(c[3],c[1]);
	}
	
	
	for(int i=1;i<=n;i++){
		if(s[i]==1) v.push_back({a[i][2]-a[i][1],a[i][3]-a[i][1]});
	}
	
	sort(v.begin(),v.end(),vv);
	l[2]=(n/2)-c[2],l[3]=(n/2)-c[3];
	
	priority_queue<ll> ff,ss;
	
	for(auto kkk:v){
		ll uu=kkk.first,vv=kkk.second;
		if(uu>=vv){
			c[1]--;
			c[2]++;
			r+=uu;
			ff.push(vv-uu);
			if(c[2]>n/2){
				r+=ff.top();
				ff.pop();
				c[3]++;
				c[2]--;
			}
		}
		else{
			c[1]--;
			c[3]++;
			r+=vv;
			ss.push(uu-vv);
			if(c[3]>n/2){
				r+=ss.top();
				ss.pop();
				c[2]++;
				c[3]--;
			}
		}
		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2) break;
	}
	
	printf("%lld\n",r);
}

int main(){
	freopen("club.in" ,"r",stdin );
	freopen("club.out","w",stdout);
	
	int o; scanf("%d",&o);
	while(o--) solve(); 
	
	return 0;
}

