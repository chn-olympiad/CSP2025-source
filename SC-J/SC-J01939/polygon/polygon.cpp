 #include<bits/stdc++.h>
 using namespace std;
 int n,k,q=3;
int a[5005]={},b[5005]={};
long long dfs(int c,int g,int floor,int t){
	if(c<=g)return 0;
 	if(c-a[1]<=g)return 1;
 	if(floor==2)return 1;
 	long long w=1;
 	for(int i=t;i>0;i--){
 		w=(w+dfs(c-a[i],g,floor-1,i-1))%998244353;
	}
	return w;
 }
 int main(){
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	cin>>n;
 	long long ans=0;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(;q<=n;q++){
		ans=(ans+dfs(b[q-1],a[q],q-1,q-1))%998244353;
	}
	cout<<ans;
	return 0;
 }