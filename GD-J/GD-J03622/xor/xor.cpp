#include<iostream>
using namespace std;
int l[550066],n,k,ans=-2e9,lst[550066],p,s=2e9,ac;bool vis[550066];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];l[i]^=l[i-1];
	}
	for(int i=0;i<=500066;i++)lst[i]=2e9;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((l[j]^l[i-1])==k){
				lst[i]=j;vis[i]=true;break;
			}
		}
	}
	for(int i=1;i<=min(s,500000);i++){
		if(vis[i]){
			s=min(s,lst[i]);
		}
	}
	for(int i=1;i<=s;i++){
		ac=0;p=i;
		while(p<500000){
			if(vis[p]){
			ac++;p=lst[p];
			}
			p++;
		}
		ans=max(ac,ans);
	}
	cout<<ans;
	return 0;
}
