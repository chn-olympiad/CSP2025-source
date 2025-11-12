#include<bits/stdc++.h>
using namespace std;
int n,a[2505],maa;
void dfs(int c,int ma,int yx,int num,int sum){
	if(yx==ma){
		if(sum>2*num){
			maa++;
			if(maa>=998244353){
				maa-=998244353;
			}
		}
		return;
	}
	if(c>n)
		return;
	
	dfs(c+1,ma,yx+1,max(num,a[c]),sum+a[c]);
	dfs(c+1,ma,yx,num,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++){
		dfs(1,i,0,0,0);
	}
	printf("%d",maa);
}
