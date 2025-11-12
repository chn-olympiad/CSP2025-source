#include<bits/stdc++.h>
/*把区间拆分成若干个，使每个区间“值为k”*/
#define N 500050
using namespace std;
int n,k,a[N],b[N],cnt,lest;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=b[lest];
		for(int j=lest+1;j<=i;j++){
			if(int(b[i]^sum)==k){
				cnt++;
				lest=i;
				break;
			}
			sum^=a[j];
		}
	}
	printf("%d\n",cnt);
	return 0;
}
/*今年前3题蛮简单的嘛，但一道题值得用 对拍 的都没有*/ 
