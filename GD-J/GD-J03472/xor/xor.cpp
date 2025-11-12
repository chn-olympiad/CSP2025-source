#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10; 
int n,k;
int a[N];
int f[N];
map<int,vector<int> > mp;
int main(){
//	freopen("xor6.in","r",stdin);
//	freopen("xor6.out","w",stdout); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],f[i]=f[i-1]^a[i];
	int r=0;
	mp[0].push_back(0);
	int ans=0;
	for(int i=1;i<=n;i++){
		int y=k^f[i];
		if(mp.count(y)&&mp[y].size()){
			int lst=mp[y][mp[y].size()-1];
			if(lst>=r) ans++,r=i;
		}
		mp[f[i]].push_back(i); 
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3*/
