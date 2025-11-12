#include<bits/stdc++.h>
using namespace std;
long long a[500005],k1,n,book[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long i,j,k,l,cnt=0,ans=0;
	scanf("%d%d",&n,&k1);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(l=1;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			int f=0;
			j=i+l-1;
			for(k=i;k<=j;k++){
				if(book[k]==1){
					f=k;
					break;
				}
			}
			if(f!=0){
				continue;
			}	
			cnt=a[i];
			for(k=i+1;k<=j;k++){
				cnt=cnt^a[k];
			}
			if(cnt==k1){
				ans++;
				for(k=i;k<=j;k++){
					book[k]=1;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
