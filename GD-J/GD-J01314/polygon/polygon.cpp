#include<bits/stdc++.h>
using namespace std;

int n,a[5005],ans=0;
void dfs(long long now,int id,int maxa,int cnt,bool f){
	if(id>n){
		return ;
	}
	if(now>maxa*2 && cnt>=3 && f==1){
		//cout<<now<<" "<<id<<" "<<maxa<<" "<<cnt<<endl;
		ans++;
		ans%=998244353;
		f=0;
	}
	dfs(now+a[id+1],id+1,max(maxa,a[id+1]),cnt+1,1);
	dfs(now,id+1,maxa,cnt,f);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0,1);
	cout<<ans<<endl;
	return 0;
}
