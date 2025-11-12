#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN=500501;
int n,num[MN];ll k,ans;
bool bo=1;
map<int,int>mp;
ll b[MN],f[MN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		b[i]=b[i-1]^a;
		mp[b[i]]=i;
		num[i]=mp[k^b[i]];
	}for(int i=1;i<=n;i++){
		if(num[i]==0){
			if(b[i]==k&&bo)f[i]=f[i-1]+1,bo=0;
			else f[i]=f[i-1];
		}else f[i]=max(f[i-1],f[num[i]]+1);
	}printf("%d",f[n]);
	return 0;
}
