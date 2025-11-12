#include<bits/stdc++.h>
using namespace std;
const int N=5e5+23;
int n,k,a[N],sum[N];
map<int,int> mp;
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
	}

	int last=0,ans=0;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		
		int q=sum[i]^k;
		if(mp.count(q)){
			int x=mp[q];

			if(x>=last){
				ans++;
				last=i;
			}
		}
		mp[sum[i]]=i;
	}

	cout << ans;
	return 0;
} 
