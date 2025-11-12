#include<bits/stdc++.h>
using namespace std;
const int N=15;
pair<int,int>x[N*N];
int n,m,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>x[i].first;
		x[i].second=i;
	}
	sort(x+1,x+n*m+1,greater<pair<int,int>>());
	for(int j=1;j<=m;++j){
		if(j&1){
			for(int i=1;i<=n;++i){
				if(x[++cnt].second==1){
					cout<<j<<" "<<i<<"\n";
					return 0;
				}
			}
		} else {
			for(int i=n;i>=1;--i){
				if(x[++cnt].second==1){
					cout<<j<<" "<<i<<"\n";
					return 0;
				}
			}
		}
	}
	return 0;
}

