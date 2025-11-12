#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
const int N=5*1e5+10;
long long n,k;
long long sz[N],sum[N],ans;
map<int,int> m;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>sz[i];
    	sum[i]=sz[i]+sum[i-1];
    	long long ls=sum[i];
    	sz[i]=0;
    	long long lj=1;
    	while(ls){
	   		sz[i]+=( (ls%2)*lj);
	   		ls/=2;
 	 		lj*=10;
		}
		ls=sum[i]+k;
		int cnt=0;
		lj=1;
		while(ls){
    		cnt+=( (ls%2)*lj);
    		ls/=2;
    		lj*=10;
		}
		if(cnt<=1e9){
			m[cnt]=i;
		}
		if(m[sz[i]]!=0){
			ans++;
		}
	}
	cout<<ans;
    return 0;
}