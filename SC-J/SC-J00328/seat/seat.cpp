#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
//const int N=1e5;
int dt[1000];
int n,m;
int ans,ams=1,ls;
int cmp(int a,int b){
	return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>dt[i];
	}
	ls=dt[1];
	sort(dt+1,dt+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(ams%2==1){
			ans++;
		}
		else{
			ans--;
		} 
		if(ans==n+1 and ams%2==1){
			ams++;
			ans=n;
		}
		if(ans==0 and ams%2==0){
			ams++;
			ans=1;
		}
		if(dt[i]==ls){
			cout<<ams<<" "<<ans;
		}
	}
    return 0;
}