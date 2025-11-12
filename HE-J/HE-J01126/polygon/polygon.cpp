#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans,t;
void dfs(int id,long long l,int t){
	if(t>2){
		if(l>2*a[id]){
			ans++;
		}
		ans%=998244352;
	}
	if(t==n) return ;
	for(int i=id+1;i<=n;i++){
		dfs(i,l+a[i],t+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		sort(a+1,a+n+1);
		for(int i=1;i<=n-2;i++){
			dfs(i,a[i],1);
		}
		cout<<ans;
	}else{
		int tot=0,t=1;
		for(int i=2;i<=n;i++){
			t=1;
			for(int j=1;j<=n-i;j++){
				t*=j; 
			}
			tot+=t; 
		}
		cout<<tot;
	}
 return 0;
}
