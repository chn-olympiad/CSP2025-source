#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[5005],ans=0;
void dfs(int now,int num,int all,int sum,int maxa){
	if(num>=all){
		if(sum>2*maxa){
			ans++;
		}
		return;
	}
	if(now==n+1){
		return;
	}
	dfs(now+1,num,all,sum,maxa);
	dfs(now+1,num+1,all,sum+a[now],max(maxa,a[now]));
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		sort(a+1,a+4);
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else if(n<=20){
		for(int i=3;i<=n;i++){
			dfs(1,0,i,0,0);
		}
		cout<<ans;
	}
	return 0;
}











