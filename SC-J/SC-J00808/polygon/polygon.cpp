#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[100000],sum[100000],s=0,cnt,maxnn=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		sum[i]=s; 
		maxnn=max(maxnn,a[i]);
	}
	if(n=3){
		if(sum[3]>maxnn*2)cout<<1;
		else cout<<0;
		return 0; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j-i+1>=3){
			long long maxn=-1;
				for(int k=i;k<=j;k++){
					maxn=max(maxn,a[k]);
				}
				if(sum[j]-sum[i]+a[i]>2*maxn)cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 