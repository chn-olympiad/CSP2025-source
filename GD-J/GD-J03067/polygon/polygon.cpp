#include<bits/stdc++.h>
using namespace std;
int n,a[5007],s[5007];
int m=998244353;
bool q[5007];
long long ans;
bool check(){
	int sum=0,x=0;
	for(int i=1;i<=n;i++){	
		if(q[i]){
//			cout<<a[i]<<" ";
			sum+=a[i];
			x=a[i];
		}
	}
	//cout<<sum;
	//cout<<endl;
	if(sum>2*x) return true;
	return false;
}
void dfs(int x,int k,int s){
	if(k==s){
		if(check()){
			ans++;
			ans%=m;
		}
		return ;
	}
	for(int i=x+1;i<=n-s+k+1;i++){
		q[i]=1;
		dfs(i,k+1,s);
		q[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i]; 
	sort(a+1,a+n+1);
	if(n<=2){
		cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int a=1;a<=n-i+1;a++){
			q[a]=1;
			dfs(a,1,i);
			q[a]=0;
		}
	}
	cout<<ans;
	return 0;
}
