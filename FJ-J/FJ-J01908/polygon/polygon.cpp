#include<bits/stdc++.h>
using namespace std;

int n;
int a[5010],x[5010],q[5010];
long long ans,ans_1;

void cj(int k,int x){
	ans_1+=a[k];
	if(x==0){
		if(ans_1>a[k]*2) ans++;
		return;
	}
	for(int i=k+1;i<=n;i++) cj(i,x-1);
	n++;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]; sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) if(a[i]!=a[i+1]) x[a[i]]=i;
	for(int i=1;i<=5000;i++) if(x[i]==0) x[i]=x[i-1];
	for(int i=1;i<=n-2;i++)
		for(int j=i+1;j<n;j++)
			ans+=max(x[a[i]+a[j]-1]-j,0),ans%=998244353;
	//for(int i=4;i<=n;i++)
	//	cj(1,i);
	cout<<ans;
	return 0;
} 
