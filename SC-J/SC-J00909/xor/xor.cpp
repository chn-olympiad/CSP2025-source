#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500010],s[500010];
int ans;
bool vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";cout<<"\n";
	for(int i=0;i<=n;i++){
		for(int l=1;l<=n-i;l++){
			int r=l+i;
			if((s[r]^s[l-1])==k){
				bool f=1;
				for(int x=l;x<=r;x++){
					if(vis[x]==1){
						f=0;break;
					}
				}
				if(!f)continue;
				ans++;
//				cout<<l<<" "<<r<<"\n";
//				cout<<(s[r]^s[l-1])<<"\n";
				for(int x=l;x<=r;x++)vis[x]=1;
			}
		}
	}
	cout<<ans;
}