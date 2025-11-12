#include<bits/stdc++.h>
#include<queue>
#define ll long long
using namespace std;

struct cy{
	ll d1,d2,d3;
}a[100005];

ll t,n,ans;
bool f[100005];
queue<int> q;

bool cmp1(cy a1,cy a2){
	return a1.d1>a2.d1;
}
bool cmp2(cy a1,cy a2){
	return a1.d2>a2.d2;
}
bool cmp3(cy a1,cy a2){
	return a1.d3>a2.d3;
}

void dfs(int k,ll sum,ll n1,ll n2,ll n3){
	if(k>n){
		ans=max(ans,sum);
		return ;
	}
	if(n1*2<n) dfs(k+1,sum+a[k].d1,n1+1,n2,n3);
	if(n2*2<n) dfs(k+1,sum+a[k].d2,n1,n2+1,n3);
	if(n3*2<n) dfs(k+1,sum+a[k].d3,n1,n2,n3+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,sizeof(a),0);
		memset(f,sizeof(f),0);
		ans=0;
		ll s1=0,s2=0,s3=0;
		cin>>n;
		
		for(int i=1;i<=n;++i){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;++i){
			if(i<=n/2){
				s1+=a[i].d1;
			}else{
				s1+=max(a[i].d2,a[i].d3);
			}
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;++i){
			if(i<=n/2){
				s2+=a[i].d2;
			}else{
				s2+=max(a[i].d1,a[i].d3);
			}
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;++i){
			if(i<=n/2){
				s3+=a[i].d3;
			}else{
				s3+=max(a[i].d1,a[i].d2);
			}
		}
		cout<<max(max(s1,s2),s3)<<"\n";
	}
	return 0;
} 
