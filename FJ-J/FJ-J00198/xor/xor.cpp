#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],pre[500005],cnt,t=1;
int main(){
	freopen("xor.in ","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) pre[i]=a[i]^pre[i-1];
    for(int i=1;i<=n;i++){
    	for(int j=t;j<=i;j++){
    		int m=pre[i]^pre[j-1];
    		if(j==i){
    			if(a[i]==k){
    			    cnt++;
					t=i+1;	
				} 
			}else if(m==k){		
				cnt++;
				t=i+1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}

