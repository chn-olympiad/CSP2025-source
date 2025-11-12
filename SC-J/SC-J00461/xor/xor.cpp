#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a,qian,q,cnt;
map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		qian=qian^a;
		int w=k^qian;
		if(mp.find(w)!=mp.end()){
			int x=mp[w]+1;
			if(q<x){
				q=i;
				cnt++;
			}
		}
		mp[qian]=i;
	}
	cout<<cnt;
	return 0;
} 