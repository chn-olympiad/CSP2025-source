#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[500005],ans,m;
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			vis[i]=1;
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		m=a[i];
		for(int j=i+1;j<=n;j++){
			if(vis[j]==1)break;
			m=int(m^a[j]);
			if(m==k){
				for(int x=i;x<=j;x++){
					vis[x]=1;
				}
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

