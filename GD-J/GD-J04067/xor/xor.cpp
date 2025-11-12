#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum[600001];
map<int,vector<int>> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	sum[0]=0;
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),sum[i]=sum[i-1]^x;
	int last=0,cnt=0;
	for(int i=0;i<=n;i++){
		if(!mp[sum[i]^k].empty()){
			vector<int>::iterator d;
			d=lower_bound(mp[sum[i]^k].begin(),mp[sum[i]^k].end(),last);
			if(d!=mp[sum[i]^k].end()) ++cnt,last=i;
		}
		mp[sum[i]].push_back(i);
	}
	printf("%d",cnt);
	return 0;
}
