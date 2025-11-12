#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int t,n;
struct Stud{
	ll a_1,a_2,a_3;
	ll ma;ll id;
};
ll cntz(Stud x){
	ll cnt=0;
	if(x.a_1==0)cnt++;
	if(x.a_2==0)cnt++;
	if(x.a_3==0)cnt++;
	return cnt;
}
Stud st[maxn];
ll sto[5];
bool cmp(Stud a,Stud b){
	ll cnta=cntz(a),cntb=cntz(b);
	if(cnta==3)return false;
	if(cntb==3)return true;
	if(cnta>cntb)return true;
	else return a.ma>b.ma;
}
bool cmpv(pair<ll,ll> a,pair<ll,ll> b){
	return a.first>b.first;
}
ll geta(Stud s,ll a){
	if(a==1)return s.a_1;
	if(a==2)return s.a_2;
	return s.a_3;
}
ll res;
void dfs(ll r,ll sum){
	if(r==n+1){
		res=max(res,sum);
		return;
	}
	if(st[r].a_1==st[r].a_2&&st[r].a_2==st[r].a_3&&st[r].a_3==0){
		dfs(r+1,sum);
		return;
	}
	if(sto[1]<n/2){
		sto[1]++;
		dfs(r+1,sum+st[r].a_1);
		sto[1]--;
	}
	if(sto[2]<n/2){
		sto[2]++;
		dfs(r+1,sum+st[r].a_2);
		sto[2]--;
	}
	if(sto[3]<n/2){
		sto[3]++;
		dfs(r+1,sum+st[r].a_3);
		sto[3]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		res=-1;
		memset(sto,0,sizeof(sto));
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>st[i].a_1>>st[i].a_2>>st[i].a_3;
		}
		dfs(1,0);
		cout<<res<<"\n";
	}
	return 0;
} 
