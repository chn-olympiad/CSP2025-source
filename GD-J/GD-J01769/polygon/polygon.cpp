#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5007;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	if(n==3){
		int x,y,z,sum=0,maxx=-1;
		cin>>x>>y>>z;
		maxx=max(maxx,x);
		maxx=max(maxx,y);
		maxx=max(maxx,z);
		sum=x+y+z;
		if(sum>2*maxx) cout<<1;
	} 
	else{
		bool f=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=1){
				f=false;
			}
		}
		if(f){
			int cnt=n*(n-1)/2-1;
			cout<<cnt;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
} 
