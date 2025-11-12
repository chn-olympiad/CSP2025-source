#include <bits/stdc++.h>
using namespace std;
int n,k,num,ans,f[500030],a[500030];
/*void dfs(long long x,long long sum){
	if(sum<f[x])
		return ;
	f[x]=max(f[x],sum);
	for(long long i=x-1;i>=0;i--){
		num=a[x]^a[i];
		if(num==k){
			sum+=1;
//			cout<<x<<" "<<i<<" "<<sum<<" "<<a[x]<<" "<<a[i]<<" "<<num<<endl;
			dfs(i,sum);
//			cout<<x<<"@@@"<<endl;
			sum-=1;
		}
		else{
//			cout<<x<<" "<<i<<" "<<sum<<endl;
			dfs(i,sum);
		}
	}
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		a[i]^=a[i-1];
	}
//	cout<<endl;
//	dfs(n,0);
	for(int i=1;i<=n;i++){
		num=0;
		for(int j=i;j<=n;j++){
			num^=a[j];
			if(num==k){
				f[j]=max(f[j],f[i-1]+1);
			}
		}
		f[i]=max(f[i-1],f[i]);
	}
	cout<<f[n]<<endl;
	return 0;
}
