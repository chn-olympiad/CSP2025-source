#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll a[N][3],n,cnt[3];
struct node{
	ll a,mx;
	int id;
	bool operator>(const node&x)const{
		return  a==x.a?mx<x.mx:a>x.a;
	}
	node(){}
	node(ll a_,ll mx_,int id_):a(a_),mx(mx_),id(id_){}
};
priority_queue<node,vector<node>,greater<node>>q[3];
int  work(int i,int j){
	if(cnt[j]==(n>>1)){
		node top=q[j].top();
		return top.mx+a[i][j]-top.a;
	}
	return a[i][j];
}
void dw(int i,int j){
	if(cnt[j]==(n>>1)){
		node top=q[j].top();
		int u=top.id;
		if(a[u][(j+1)%3]>a[u][(j+2)%3]||(a[u][(j+1)%3]==a[u][(j+2)%3]&&cnt[(j+1)%3]<cnt[(j+2)%3]))
		dw(u,(j+1)%3);
		else dw(u,(j+2)%3);
		q[j].pop();
		--cnt[j];
	}
	q[j].emplace(node(a[i][j],max(a[i][(j+1)%3],a[i][(j+2)%3]),i));
	++cnt[j];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)
		for(int j=0;j<3;++j)
		cin>>a[i][j];
		int ans=0;
		for(int i=1;i<=n;++i){
			int a1=work(i,0),a2=work(i,1),a3=work(i,2);
			if((a1>a2&&a1>a3)||(a1==a2&&a1>=a3&&cnt[0]<=cnt[1])||(a1==a3&&a1>=a2&&cnt[0]<=cnt[2]))ans+=a1,dw(i,0);
			else if(a2>a3||(a2==a3&&cnt[1]<=cnt[2]))ans+=a2,dw(i,1);
			else ans+=a3,dw(i,2);
		}
		for(int j=0;j<3;++j){while(!q[j].empty())q[j].pop();cnt[j]=0;}
		cout<<ans<<"\n";
	}
}
