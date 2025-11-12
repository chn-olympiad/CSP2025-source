#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];

int mypow(int n){
	if(n==1) return 2;
	return 2*mypow(n-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=mypow(n);i++){
		int tmp=i;
		int tmpa[22];
		int tmpb[22];
		int k=0;
		while(tmp){
			tmpa[++k]=tmp%2;
			tmp/=2;
		}
		for(int i=1;i<=k;i++){
			tmpb[i]=tmpa[k-i+1];
		}
		int maxn=-1e9-10;
		int sum=0;
		for(int j=1;j<=n;j++){
			if(tmpb[j]){
				sum+=a[j];
				maxn=max(a[j],maxn);
			}
		}
		if(sum>maxn*2){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

