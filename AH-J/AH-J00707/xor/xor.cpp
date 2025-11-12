#include<bits/stdc++.h>
using namespace std;
int a[500005];
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int st=0;
	int ans=0;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		st^=a[i];
		mp[st]++;
		//cout<<st<<" "<<(st^k)<<"\n";
		if(mp[st^k]>=1+((st^k)==st)){
			ans++;
			mp.clear();
			st=0;
			mp[0]=1;
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
