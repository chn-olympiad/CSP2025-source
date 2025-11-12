#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
	}
	map<int,int>mp;
	int res=0;
	for(int i=1,last=0;i<=n;i++){
		mp[s[i-1]]=i;
		if(mp.count(s[i]^k)){
			if(mp[s[i]^k]<=last) continue;
			res++;
			//cerr<<i<<" "<<mp[s[i]^k]<<"\n";
			last=i;
		}
	}
	printf("%d\n",res);
	return 0;
}