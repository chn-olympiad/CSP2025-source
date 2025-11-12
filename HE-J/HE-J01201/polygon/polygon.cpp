#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005];
long long sum=0,o;
bool cmp(int aa,int bb){
	return aa>bb;
}
void dfs(int m,long long ans,long long mx,int cnt,int i){
	if(cnt>=m){
		if(ans>2*mx){
			sum++;
			sum%=998244353;
		}
		return ;
	}
	for(int j=i+1;j<=n;j++){
		dfs(m,ans+a[j],mx,cnt+1,j);
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		int sum=0;
		sum=a[1]+a[2]+a[3];
		if(sum>2*a[1]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		o=0;
		for(int j=i+1;j<=n;j++){
			o+=a[j];
		}
		if(o<a[i]){
			continue;
		}
		for(int j=3;j<=n;j++){
			dfs(j,a[i],a[i],1,i);
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
