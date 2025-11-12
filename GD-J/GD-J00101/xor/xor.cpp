#include<bits/stdc++.h>
using namespace std;
int n,k,num[500005],cnt,l=1,now;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",num+i);
		now=num[i];
		if(num[i]==k){
			cnt++;
			l=i;
			continue;
		}
		for(int j=i-1;j>=l;j--){
			if(now==k){
				cnt++;
				l=i;
				continue;
			}
			now=now^num[j];
		}
	}
	printf("%d",cnt);
	return 0;
}

