#include<bits/stdc++.h>
using namespace std;
int n,k,ans,l;
int a[500009];
int p[500009];
bool f=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1){
			f=0;
		}
		p[i]=p[i-1]^a[i];
	}
	if(f){
		if(k){
			for(int i=1;i<=n;i++){
				if(a[i]){
					ans++;
				}
			}
			printf("%d",ans);
			return 0;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]){
					a[i+1]=0;
				}else{
					ans++;
				}
			}
			printf("%d",ans);
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=l;j<i;j++){
			if((p[i]^p[j])==k){
				ans++;
				l=i;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
