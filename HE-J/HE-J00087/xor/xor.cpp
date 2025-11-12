#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i==1){
            b[1]=a[1];
        }
        else
            b[i]=b[i-1]^a[i];
    }
    if(b[1]==k)
        ans++;
    int o=1;
    while(o!=n){
        for(int i=o+1;i<=n;i++){
    		if(b[i]^b[o]==k)
    			ans++,o=i;
   		}
   		o++;
	}
    printf("%d",ans-1);
	return 0;
}
