#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
struct node{
	ll name,tot,were;
	bool is_xiao_r;
}a[N][N],b[N];
ll n,m,idx;
bool comp(node s1,node s2){
	return s1.tot>s2.tot;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll len=n*m;
	b[1].is_xiao_r=1;
	for(ll i=1;i<=len;++i){
		cin>>b[i].tot;
		b[i].name=i;
	}
	sort(b+1,b+len+1,comp);
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=m;++j){
			a[i][j].tot=b[n*(i-1)+j].tot;
			a[i][j].name=b[n*(i-1)+j].name;
			a[i][j].is_xiao_r=b[n*(i-1)+j].is_xiao_r;
		}
	}
	for(ll i=1;i<=n;++i){
		if(i&1){
			for(ll j=1;j<=m;++j){
				if(a[i][j].is_xiao_r){
					cout<<i<<" "<<j;
					return 0;
				}
//				++idx;
//				a[i][j].were=idx;
			}
		}
		else{
			for(ll j=m;j>=1;--j){
				if(a[i][j].is_xiao_r){
					cout<<i<<" "<<m-j+1;
					return 0;
				}
//				++idx;
//				a[i][j].were=idx;
			}
		}
	}
//	for(ll i=1;i<=n;++i){
//		for(ll j=1;j<=m;++j){
//			cout<<a[i][j].name<<":"<<a[i][j].tot<<" ";	
//		}
//		cout<<"\n";
//	}
//	for(ll i=1;i<=n;++i){
//		for(ll j=1;j<=m;++j){
//			if(a[i][j].is_xiao_r){
//				cout<<j<<" "<<i;
//				cout<<"\n"<<a[i][j].tot;
//				return 0;
//			}
//		}
//	}
	return 0;
}