#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],q[500005],cnt;
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q[i]=q[i-1]^a[i];
	}
	int lastl=0,lastr=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int diff=q[r]^q[l-1];
			if(l==r)diff=a[r];
			if(diff==k&&!vis[l]&&!vis[r]){
				if(lastl<l&&lastr>l)continue;
				vis[l]=vis[r]=1;
				lastl=l,lastr=r;
				cnt++;
				break;
			}
		} 
	}
	cout<<cnt;
	return 0;
} 
