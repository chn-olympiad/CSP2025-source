#include<bits/stdc++.h>
using namespace std;
int n,a[500010],b[50010],ans;
bool cmp(int a,int b){
	return a>b;
}
inline int f(int d,int l,int r){
	int ans=0;
	for(int i=r;i>=l;i--){
		if(a[i]<d){
			ans=(ans+1)%99824435;
			if(d-a[i]>1)ans=(ans+f(d-a[i],i+1,r))%99824435;
		}
		else break;
	}return ans%99824435;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int d=b[n]-b[i-1]-a[i]*2;
		if(d<1)continue;
		ans=(ans+f(d,i+1,n)+1)%99824435;
	}cout<<ans;
	return 0;
}

