#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==0){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==0){
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1){
				ans++;i++;
			}
		}
		printf("%d",ans);
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0&&a[i+1]==1){
				ans++,i++;
			}
			else if(a[i]==1){
				if(a[i+1]==0){
					ans++;i++;
				}
				else if(a[i+2]==1){
					ans++;i+=2;
				}
			}
		}
		printf("%d",ans);
	}
	return 0;
}
