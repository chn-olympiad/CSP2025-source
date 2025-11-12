#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],s[N],vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			if(n-cnt<l)break;
			int lef=i,righ=i+l-1;
			int t=s[righ]^s[lef-1];
			if(t==k){
				bool f=0;
				for(int kk=lef;kk<=righ;kk++){
					if(vis[kk]){
						f=1;break;
					}
				}
				if(!f){
					ans++;
					for(int kk=lef;kk<=righ;kk++)vis[kk]=1;
					cnt+=(righ-lef+1);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
