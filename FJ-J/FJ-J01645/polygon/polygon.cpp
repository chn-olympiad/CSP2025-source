#include<bits/stdc++.h>
using namespace std;
int n,a[12345],ans,v[12345],t[11234];
int ccc(int x,int y){
	int xxx=1,xx=1;
	for(int i=y;i>x;i--){
		xxx=xxx*i;
		xxx%=998244353;
	} 
	for(int i=2;i<=y-x;i++){
		xx=xx*i;
		xx%=998244353;
	}
	return xxx/xx;
}
void dfs(int num,int m,int sum,int s){
	if(num>n)return; 
	if(num>=3){
		if(sum>m*2){
			ans=(ans+1)%998244353;
			//cout<<num<<" "<<m<<" "<<sum<<endl;
		}
	}
	for(int i=s;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			//cout<<a[i]<<endl;
			dfs(num+1,max(m,a[i]),sum+a[i],i+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++; 
	}
	if(t[1]==n){
		int www=0;
		for(int i=3;i<=n;i++){
			www+=ccc(i,n);
			www%=998244353;
		}
		cout<<www;
	}else{
		dfs(0,0,0,1);
		cout<<ans%998244353;
	}
	return 0;
} 
