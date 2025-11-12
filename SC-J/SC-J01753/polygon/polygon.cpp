#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[5006]{};
int n;
long long dfs(int num1,long long num,long long maxn,int last){
	if(num1==n+1){
		return ans;
	}
	long long numm;
	long long maxx;
	long long prev=0;
	bool no=0;
	for(int i=last+1;i<=n;i++){
		if(a[i]==0)continue;
		numm=num;
		numm+=a[i];
		maxx=maxn;
		maxx=max(maxx,a[i]);
		if(num1>=3){
			if(numm>2*maxx){
				ans++;
				ans%=998244353;
			}
			prev=dfs(num1+1,numm,maxx,i);
		}else{
			prev=dfs(num1+1,numm,maxx,i);
		}
		
	}
	return ans;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n+1);
	cout<<dfs(1,0,-1,0);
	return 0;
} 