#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int sum=0,j=1,nxt=2;
	while(j<=n){
		sum=sum^a[j];
		if(sum==k){
			ans++;
			sum=0;
			j++;
			nxt=j+1;
		}else if(!sum){
			j=nxt;
			nxt=j+1;
		}else{
			j++;
		}
	}
	printf("%d",ans);
	return 0;
}
