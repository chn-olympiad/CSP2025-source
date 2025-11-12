#include<bits/stdc++.h>
using namespace std;
int a[5003],cnt,c[5003],sum,n;
bool check(){
	int maxn=0,ans=0;
	for(int i=1;i<=cnt;i++){
		maxn=max(maxn,a[c[i]]);
		ans+=a[c[i]];
	}
	return ans>2*maxn&&cnt>=3;
}
void dfs(int now,bool pick){
	if(now==n+1){
		return;
	}
	if(pick==1){
		c[++cnt]=now;
	/*	for(int i=1;i<=cnt;i++){
	//		cout<<c[i]<<" ";
		}*/
	//cout<<endl;
		if(check()){
			sum++;
		}
	}
	dfs(now+1,0);
	dfs(now+1,1);
	if(pick==1){
		cnt--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0);
	printf("%d",sum);
	return 0;
}
