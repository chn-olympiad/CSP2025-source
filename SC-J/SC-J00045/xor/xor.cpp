#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
map<int,int> mp;
int n,k,s[N],cnt,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		s[i]=s[i]^s[i-1];
	}
	for(int i=1;i<=n;i++){
		ll d=k^s[i-1];
		for(int j=i;j<=n;j++){
			if(s[j]==d){
				if(mp.count(j)){
					mp[j]=max(mp[j],i);
				}
				else mp[j]=i;
				break;
			}
		}
	}
	int i=0;
	for(auto [x,y]:mp){
		if(y>i){
			ans++;
			i=x;
		}
	}
	cout<<ans;
	return 0;
}