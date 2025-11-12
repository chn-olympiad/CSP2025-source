#include<bits/stdc++.h>
using namespace std;
int a[5010];
int cnt=0,u,n;
void se(int step,int maxn,int p,int sum){//书架DFS
	if(step>=u){
		if(sum>2*maxn){                                                                                                                                                                                                                                                                                            																																																																																																																																																																																																																																																										
			cnt=(cnt+1)%998244353;
		}
		return ;
	}
	for(int i=p+1;i<=n;i++){
		if(step+1<=u){
			 se(step+1,max(maxn,a[i]),i,sum+a[i]);	
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){//区间长度
		u=i;
		for(int j=1;j<=n;j++){//枚举根节点
			se(1,a[j],j,a[j]);//(步数，最大值，当前下标，当前总和)
		}
	}
	cout<<cnt;
	return 0;
}
