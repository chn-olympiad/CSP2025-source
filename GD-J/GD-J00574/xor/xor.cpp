#include<bits/stdc++.h>
using namespace std;
//CSP-S RP++
const int N=5e5+5,M=1<<21;
int n,f[N],lst[M],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(lst,-1,sizeof(lst));
	lst[0]=0;
	for(int i=1,a,sum(0);i<=n;++i){
		scanf("%d",&a);
		sum^=a;
		if(lst[sum^k]>=0)
			f[i]=f[lst[sum^k]]+1;
		lst[sum]=i;
		f[i]=max(f[i],f[i-1]);
	}
	printf("%d",f[n]);
	return 0;
}
/*
	已完成今日速通CSP-J大学习
	已完成今日立定跳远3km大学习
	已完成今日我对着铁制的板凳踢了一下，然后把那堆钢栏杆在地上滚了一下，然后把椅子夹在篮筐上大学习
	所以大学习是什么...... 
*/ 
