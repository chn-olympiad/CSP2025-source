#include<bits/stdc++.h>
using namespace std;
int a[5000];
const int k=998244353;
int powk2(int s){
	if(s==1) return 2;
	if(s==0) return 1;
	return (powk2(s/2)*powk2(s/2)*powk2(s%2))%k;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0,k=1,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0) k=0;
		if(a[i]==1) s++;
	}
	if(n<=23){
		sort(a+1,a+n+1);
		for(int i=1;i<=(1<<n);i++){
			int sum=0,m=0;
			for(int j=1;j<=20;j++){
				sum+=a[((i&(1<<j))>>j)*j];
				m=max(m,a[((i&(1<<j))>>j)*j]);
			}
			if(sum>2*m) cnt++;
		}
		cout<<cnt;
	}else if(k){
		cout<<powk2(s)-1-s-s*(s-1)/2;
	}
	return 0;
}
