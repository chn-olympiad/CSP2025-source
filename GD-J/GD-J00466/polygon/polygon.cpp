#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
int n,a[5005];
ll dfs(int k,int ma,ll sum,int x){
	ll cnt=0;
	if(x>=3&&sum>(ma*2))cnt++;
	
	for(int i=k+1;i<=n;i++){
		cnt+=dfs(ll(i),max(ma,a[i]),sum+a[i],x+1);
	}
	return cnt;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
}

cout<<(dfs(0,0,0,0))%998244353;
fclose(stdin);
fclose(stdout); 
return 0;
}
