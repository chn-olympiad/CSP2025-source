#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,sum;
int a[5005];
int b[5005],cur;
void res(int x,int s,int p){
	if (s==-1){
		if (sum>a[p]*2){
			ans++;
			ans%=mod;
		}
		return;
	}
	for (int i=p+1;i<=n-s;i++){
		b[++cur]=a[i],sum+=a[i];
		res(x,s-1,i);
		sum-=a[i],b[cur]=0,cur--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=3;i<=n;i++) sum=0,res(i,i-1,0),ans%=mod;
	cout<<ans%mod<<endl;
	return 0;
}
