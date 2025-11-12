#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],cnt,l;
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		mp[b[i]]=-1e8;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++,l=i;
		}
		else if(mp[b[i]^k]>=l){
			cnt++,l=i;
		}
		mp[b[i]]=i;
	}
	printf("%d",cnt);
	return 0;
}
