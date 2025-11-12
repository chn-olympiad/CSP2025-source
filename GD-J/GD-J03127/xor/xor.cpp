#include<bits/stdc++.h>
using namespace std;
const int ri=5e5+5;
int n,k,a[ri],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
} 
