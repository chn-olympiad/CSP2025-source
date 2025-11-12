#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int a[500005];
bool vis[500005];
int mx;
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int ans=0;
			for(int i=l;i<=r;i++){
				ans^=a[i];
			}
			if(ans==k){
				cnt++;
				l=r;
				break;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}

