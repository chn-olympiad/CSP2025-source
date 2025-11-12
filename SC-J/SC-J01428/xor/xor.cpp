#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,k,tot[N],a[N],ans,lst;
unordered_map<int,queue<int> > mp;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)	
		scanf("%d",&a[i]);
		mp[0].push(0);
	for(int i=1;i<=n;++i){
		tot[i]=tot[i-1]^a[i];
		mp[tot[i]].push(i);
	}
	for(int i=1;i<=n;++i){
		if(!mp[tot[i]^k].empty()){
			while(!mp[tot[i]^k].empty()&&mp[tot[i]^k].front()<lst)
				mp[tot[i]^k].pop();
			if(mp[tot[i]^k].empty()||mp[tot[i]^k].front()>=i) 
				continue;
			++ans;
			lst=i;
			mp[tot[i]^k].pop();
		}
	}
	printf("%d",ans);
	return 0;
}
