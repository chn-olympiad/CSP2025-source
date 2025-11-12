#include<bits/stdc++.h>
using namespace std;
map<int,bool> mp;
int n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int ss=0;
	mp[k]=true;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ss^=x;
		if(mp[ss]){
			ans++;
			mp.clear();
		}
		mp[ss^k]=true;
	}
	printf("%d",ans);
	return 0;
}

