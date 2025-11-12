#include<bits/stdc++.h>
using namespace std;
int n,a[1010],v[100],ans=0;
int pd(){
	int sum=0,ma=0,num=0;
	for(int i=1;i<=n;i++) {
	    if(v[i]==1) sum++;
		
	}
	if(sum<3) return false;
	for(int i=1;i<=n;i++){
		if(v[i]==1){
			ma=max(ma,a[i]);
			num+=a[i];
		}
	}
	
	if(num>2*ma) return true;
	else return false;
}
void dfs(int x){
	if(x==n+1){
		if(pd()) ans++;
		return ;
	}
	v[x]=1;
	dfs(x+1);
	v[x]=0;
	dfs(x+1);
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<3){
    	cout<<0;
	}else if(n==3){
		int m=a[1]+a[2]+a[3];
		int k=max(a[1],max(a[2],a[3]));
		if(m>2*k) cout<<1;
		else cout<<0;
	}else{
		if(n<=20) dfs(1);
		cout<<ans;
	}
	return 0;
}

