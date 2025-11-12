#include<bits/stdc++.h>
using namespace std;
int x,k,a[500005],top=1,now,cnt;
vector<int> v;
bool vis[1048577];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&x,&k);
	for(int i=1;i<=x;i++){
		scanf("%d",&a[i]);
		now^=a[i];
		if(vis[now^k]==1||now==k){
			cnt++;
			for(int i=0;i<=int(v.size())-1;i++){
				vis[v[i]]=0;
			}//O(n)
			now=0;
			v.clear();
		}
		vis[now]=1;
		v.push_back(now);
	}
	printf("%d",cnt);
	return 0;
}
