#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int mod=998244353;
int n,ans,mx;
int a[5005],sum[5005];
bool vis[5005];
string s;
set<string> q;
int t(int a,int b){
	int cs=1,bcs=1;
	for(int i=b;i>=b-a+1;i--){
		bcs=(bcs*i)%mod;
	}
	for(int i=1;i<=a;i++){
		cs=(cs*i)%mod;
	}
	return bcs/cs;
}
void f(int t,int mxi,int h,int j){
	if(t==n+1){
		if(h<=mxi*2){
			return ;
		}
		q.insert(s);
	}
	if(sum[n]-sum[t-1]+h<=mxi*2){
		return ;
	}
	for(int i=j+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			s+=char(i+'0');
			f(t+1,max(mxi,a[i]),h+a[i],i);
			vis[i]=false;
			s=s.substr(0,s.size()-1);
			f(t+1,mxi,h,i);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		for(int i=3;i<=n;i++){
			ans=(ans%mod+t(i,n)%mod)%mod;
		}
	}else if(n<=20){
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		f(1,0,0,0);
		for(auto it=q.begin();it!=q.end();it++){
			ans++;
			ans%=mod;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
