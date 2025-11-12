#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,l,r,num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(i>=l&&i<=r)continue;
		for(int j=i;j<=n;j++){
			cnt^=a[j];
			if(cnt==k){
				l=i;
				r=j;
				num++;
				break;
			}
		}
		cnt=0;
	}
	printf("%d",num);
	return 0;
}