#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
ll n,a[N],sumt,suml,pre[N],q;
void dfs(int i,int q){
	if(a[i]>=q){
		return;
	}else if(q-a[i]>0){
		sumt++;
		sumt%=998244353;
	}
	
	if(q-a[i]>a[0]){
		dfs(0,q-a[i]);
	}else{
		return;
	}
	dfs(i+1,q);
}
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+0,a+n,cmp);
	if(n==3){
		if(a[2]*2<pre[2]){
			sumt++;
		}
	}else{
		for(int i=n-1;i>=3;i--){
			if(pre[i]>2*a[i]){
				sumt++;
				q=pre[i]-2*a[i];
				dfs(0,q);
			}
		}
	}
	sumt%=998244353;
	printf("%lld",sumt);
	return 0;
}
