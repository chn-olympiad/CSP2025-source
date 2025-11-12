#include<bits/stdc++.h>
using namespace std;
long long a[5005],zong;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=(1<<n);i++){
		long long sum=0,s=0,ma=-1;
		for(long long j=0;j<n;j++){
			if(i&(1<<j)){
				sum++;
				s+=a[j+1];
				ma=max(ma,a[j+1]);
			}
		}
		if(s>ma*2&&sum>=3){
			zong++;
		}
	}
	cout<<zong;
	return 0;
}
