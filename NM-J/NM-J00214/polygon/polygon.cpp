#include <bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5010],pd[5010],b[5010];
void print(){
	long long sum=0,maxn=0;
	for (int i=1;i<=n;i++){
		sum+=b[i];
		maxn=max(maxn,b[i]);
	}
	if (sum>maxn*2){
		ans++;
		ans=ans%998244353;
	}
}
void dfs(int i,int r){
	if (i>r){
		print();
		return ;
	}
	for (int j=1;j<=n;j++){
		if (i<j && pd[j]!=1){
			pd[j]=1;
			b[i]=a[j];
			dfs(i+1,r);
			pd[j]=0;
			b[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long c=0,d=-1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		c+=a[i];
		d=max(d,a[i]);
	}
	sort(a+1,a+n+1);
	if (c>d*2)ans++;
	for (int i=3;i<=n;i++){
		dfs(1,i);
	}
	cout<<ans;
	return 0;
}
