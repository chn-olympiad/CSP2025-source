#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],b[1005],f[1005],g[1005],ans;
void work(){
    for(int i=1;i<=n;i++){	
		for(int j=n;j>=i;j--) g[j]=a[j]^g[j-1];
		for(int j=1;j<=n;j++){
		    if(j>=i&&f[j]==0&&g[j]==k){
			    for(int l=j-i+1;l<=j;l++) f[l]=1; 
			    ans++;
			}
		    else if(f[j]) j=min(j+i-1,b[j]-1);
		}
		for(int id=n+1,j=n;j>=1;j--)
		    if(f[j]) b[j]=id,id=j;
	}
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	work();
	cout<<ans;
    return 0;
}
