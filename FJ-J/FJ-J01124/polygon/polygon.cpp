#include<bits/stdc++.h> 
using namespace std;
int a[5005],n;
long long ans=0,z[5005];
void qwq(int k,int s,int ma){
	if(k<1)return;
	for(int i=k;i>=1;i--){
		if(s+a[i]>ma){
			ans+=z[i-1];
			ans%=998244353;
		}else{
			qwq(i-1,s+a[i],ma);
		}
	}return;
}
int main(){
	int ff=1;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)ff=0;
	}sort(a+1,a+n+1);
	z[0]=1;
	for(int i=1;i<=n;i++){
		z[i]=z[i-1]*2;
		z[i]%=998244353;
	}if(ff){
		for(int i=1;i<=n-2;i++){
			ans+=(z[i-1]*((n-i)*(n-i-1)/2))%998244353;
			ans%=998244353;
		}cout<<ans%998244353;
		return 0;
	}for(int i=n;i>=3;i--){
		for(int j=i-1;j>=2;j--){
			qwq(j-1,a[i]+a[j],2*a[i]);
		} 
	}cout<<ans%998244353;
	return 0;
}
