#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500001];
map<int,int>mp,o;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	int k=1;
	for(int i=1;i<=n;i++){
		mp[i]=mp[i-1]^a[i];
		o[mp[i]]=i; 
		if(a[i]==m) 
		{
			cnt++;
			k=i;
			continue;
		}
		if(o[mp[i]^m]>0&&o[mp[i]^m]>=k){
			cnt++;
			k=i;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

