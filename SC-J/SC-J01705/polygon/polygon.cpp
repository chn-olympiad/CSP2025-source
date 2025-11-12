#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[5003],maxx;
map<string,int> t;
void dfs(int sum,int d,int len){
	if(len<3) return ;
	long long c=0;
	for(int i=1;i<=n;i++) c=max(c,a[i]);
	if(sum>2*c){
		string s="";
		for(int i=1;i<=n;i++)
			s+=to_string(a[i]);
		t[s]++;
		if(t[s]==1) ans++;}
	for(int i=1;i<=n;i++){
		if(a[i]>=d){
			c=a[i];
			a[i]=0;
			dfs(sum-c,c,len-1);
			a[i]=c;}}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(a[i],maxx);}
	if(maxx==1){
		for(int i=3;i<=n;i++){
			long long sum=1; 
			for(int j=1;j<=i;j++)
				sum*=(n-j+1),sum/=j,sum%=998244353;
			ans+=sum,ans%=998244353;}
		cout<<ans;
		return 0;}
	sort(a+1,a+1+n);
	dfs(sum,0,n);
	cout<<ans;
	return 0;
}