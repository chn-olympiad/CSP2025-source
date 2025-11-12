#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,a[5010];
long long ans,te;
bool f;
bool cmp(int a,int b){
	return a>b;
}
long long c(int s,int d){
	if(2*s>d){
		s=d-s;
	}
	long long w=1;
	for(int i=d;i>=d-s+1;i--){
		w=w*i;
	}
	for(int i=2;i<=s;i++){
		w/=i;
	}
	return w%N;
}
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(a[1]==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				te=a[i]+a[j];
				for(int l=k;l<=n;l++){
					te+=a[l];
					if(2*a[i]<te){
						f=1;
						ans++;
						for(int t=1;t<=n-l;t++){
							ans+=c(t,n-l);
							ans%=N;
						}
						break;
					}
				}
			}
				if(f==0) break;
		}
	}
	cout<<ans;
	return 0;
}
