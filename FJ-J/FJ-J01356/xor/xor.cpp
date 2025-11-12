#include<bits/stdc++.h>
using namespace std;
unordered_map<int,bool>mp;
int a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int s=0,ans=0;
	for(int i=1;i<=n;i++){
		s^=a[i];
		if(s==k||mp[s^k]){
			mp.clear();
			ans++;
			s=0;
		}else{
			mp[s]=1;
		}
	}
	cout<<ans;
	return 0;
}
