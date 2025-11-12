#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[5050],ans=0;
bool b[5050];
int n;
void dfs(int step,long long k){
//	ans+=k;
	if(step>5000){
		return;
	}
	long long g=0,ma=0;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			g++;
			ma=max(ma,a[i]);
		}
	}
	if(g>=3){
		if(ma*2<k){
			ans++;
			ans%=998244353;
//			cout<<ma<<" "<<k<<endl;
//			for(int i=1;i<=n;i++){
//				cout<<b[i]<<" ";
//			}
//			cout<<endl;
		}
	}
	for(int i=step;i<=n;i++){
		if(b[i]){
			b[i]=false;
			dfs(i+1,k+a[i]);
			b[i]=true;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=true;
	}
	sort(a+1,a+1+n);
	dfs(0,0);
	cout<<ans%998244353;
	return 0; 
}
