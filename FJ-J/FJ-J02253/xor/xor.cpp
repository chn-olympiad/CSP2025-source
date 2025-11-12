#include<bits/stdc++.h>
using namespace std;
int a[500010],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool f=true;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]>1){
			f=false;
			break;
		}
	}if(f){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==k) ans++;
				else if(a[i]==a[i+1]&&i+1<=n){
					ans++;
					i++;
				}
			}
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==k) ans++;
				else if(a[i]!=a[i+1]&&i+1<=n){
					ans++;
					i++;
				}
			}
		}printf("%d",ans);
	}
	return 0;
}
