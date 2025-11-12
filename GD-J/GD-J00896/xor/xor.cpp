#include<bits/stdc++.h>

using namespace std;

constexpr int N = 5e5+7;

int a[N],n,k,lx[N];

int main(){freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i = 1;i<=n;i++){
		lx[i] = lx[i-1]^a[i];
	}
	unordered_map<int,int> mp;
	int cnt = 0,last = 0;
	for(int i = 1;i<=n;i++){
		if(a[i]==k){
			last = i;
			cnt++;
			mp[lx[i]] = i;
			continue;
		}
		if(last == 0&&lx[i] == k){
			last = i;
			cnt++;
			mp[lx[i]] = i;
			continue;
		}
		int x = k^lx[i];
		if(mp[x]!=0){
			int l = mp[x];
			if(last <= l){
				cnt++;
				last = i;
				mp[x] = 0;
			}
		}
		mp[lx[i]] = i;
	}
	cout<<cnt;
	return 0;
}
