#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,l[5009],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&l[i]);
	}
	if(n==3){
		if(l[0]+l[1]+l[2]>max(max(l[0],l[1]),l[2])*2){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}
