#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int ba,bb;
	ba=bb=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=1)ba=0;
		if(a[i]>1)bb=0;
	}
	if(ba){
		printf("%d\n",n/2);
		return 0;
	}
	if(bb){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;++i){
				if(a[i]==0)++ans;
				else{
					if(a[i+1]==1){
						++ans;
						++i;
					}
				}
			}
		}
		else{
			for(int i=1;i<=n;++i){
				if(a[i]==1)++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
