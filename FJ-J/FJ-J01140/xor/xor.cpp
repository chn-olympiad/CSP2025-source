#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
map<int,int> mp;//map”≥…‰
int want,n,ans = 0;
int a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,want;scanf("%d%d",&n,&want);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = n;i >= 1;i--){
		sum[i] = sum[i + 1] ^ a[i];
	}
	int now = 0;
	mp[0] = 1;
	for(int i = 1;i <= n;i++){
		if((a[i] ^ want) == 0){
			ans++;
			mp.clear();
 
		}
		else if(mp[a[i] ^ want ^ sum[i]]){
			ans++;
			mp.clear();
 
		}
		else{
			mp[sum[i]] = 1;
		}
	}
	printf("%d",ans);
	return 0;
}

