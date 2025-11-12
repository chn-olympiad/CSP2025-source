#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=1e5+5;
vector<int>a;
int n,m;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	int t=a[0],idx=0;
	sort(a.begin(),a.end(),greater<>());
	for(int i=0;i<n*m;i++){
		if(a[i]==t){
			idx=i+1;
			break;
		}
	}
	int res=ceil(1.0*idx/n);
	if(res%2)cout<<res<<' '<<(idx%n!=0?idx%n:n)<<'\n';
	else cout<<res<<' '<<(idx%n==0?1:n-(idx%n)+1)<<'\n';
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}