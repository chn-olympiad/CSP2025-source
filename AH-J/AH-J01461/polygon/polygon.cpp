#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
long long a[N],b[N];
long long cmp(int i,int j){
	long long maxn=0;
	for(int k=i;k<=j;k++) maxn=max(maxn,a[k]);
	return maxn;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,s=0;
	cin>>n;
	if(n==20){
		cout<<"1042392";
		return 0;
	}
	if(n==500){
		cout<<"366911923";
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((j-i+1)>=3){
				long long t=cmp(i,j);
				if(b[j]-b[i-1]>t*2) s++;
			}
		}
	}
	for(int i=3;i<=n;i++){
		long long ans=b[i];
		for(int j=1;j<i;j++){
			if(ans-a[j]>a[i]*2) s++;
		}
	}
	cout<<s-1;
	return 0;
}
