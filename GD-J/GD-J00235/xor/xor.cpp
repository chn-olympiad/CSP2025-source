#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],f[500010][2];
map <int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=sum^a[i];
		if(mp[sum^k]==0&&(sum^k)!=0) {
			f[i][1]=0;
		}
		else f[i][1]=max(f[mp[sum^k]][0],f[mp[sum^k]][1]) + 1;
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		mp[sum]=i;
	}
	cout<<max(f[n][0],f[n][1])<<endl;
	return 0;
}
