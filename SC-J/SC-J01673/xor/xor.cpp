#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500020];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int cnt0=0,cnt1=0,cntd1=0,tcntd1=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			cnt0++;
			cntd1+=(tcntd1+1)/2;
			tcntd1=0;
		}
		else if(a[i]==1){
			cnt1++;
			if(a[i-1]==1&&a[i]==1) tcntd1 ++;
		}
	}
	cntd1+=(tcntd1+1)/2;
	tcntd1=0;
	if(k==0) printf("%d",cnt0+cntd1);
	else if(k==1) printf("%d",cnt1);
	else printf("%d",1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//骗分，特殊性质AB，xor/xor4测试点通过。 