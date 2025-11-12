#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ma,ans,cnt;
int je(int x,int y){
	int w=1;
	for(int i=x;i>=x-y+1;i--){
		w*=i;
	}
	return w;
}
void dfs(int w,int mx,int all,int k,int f){
	if(k>=3 and mx*2<all and f==0){
		cnt++;
//cout<<s<<endl;
	}
	if(w>n){
		return ;
	}
	
	dfs(w+1,max(mx,a[w]),all+a[w],k+1,0);
	dfs(w+1,mx,all,k,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(n<=2){
		cout<<0;
	}else if(n<=3){
		cout<<1;
	}else if(ma==1){
		for(int i=1;i<=n;i++){
			ans+=je(n,i)/je(i,i);
			ans%=998244353;
		}
		cout<<ans<<endl;
	}else if(n<=20){
		dfs(1,0,0,0,0);
		cout<<cnt<<endl;
	}else{
		
	}
	return 0;
}
