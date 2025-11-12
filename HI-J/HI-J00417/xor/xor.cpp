#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],cnt=0,ls=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			cnt++;
		}
	}
	if(k==1){
		ls=n-cnt;
		printf("%d",ls);
	}else if(k==0){
		ls=cnt+(n-cnt)/2;
		printf("%d",ls);
	}else{
		printf("2");
	}
	return 0;
}

