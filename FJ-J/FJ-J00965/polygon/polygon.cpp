#include<bits/stdc++.h>
using namespace std;
int n,stick[10001],choose[10001],use[10001],num=0,maxn=-1,all=0,p;
void dfs(int b,int now,int xb){
	if(now-1==b){
		for(int i=1;i<=b;i++){
			if(choose[i]>=maxn){
				maxn=choose[i];
			}
			all+=choose[i];
		}
		if(all>maxn*2){
			num++;
			num=num%998244353;
		}
		maxn=-1;
		all=0;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(use[i]!=1 && xb<i){
			use[i]=1;
			choose[now]=stick[i];
			dfs(b,now+1,i);
			use[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	p=n;
	for(int i=1;i<=n;i++){
		cin>>stick[i];
	}
	while(1){
		dfs(p,1,0);
		p--;
		if(p<3){
			break;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
