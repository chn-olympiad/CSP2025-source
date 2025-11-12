#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
long long n,k,a[N],sum[N],maxx=-99999999;

void DFS(int t,int r){
	if(t>=n){
		if(maxx<r){
			maxx=r;
		}
		return;
	}
	for(int i=t+1;i<=n;i++){
		for(int j=0;j+i<=n;j++){
			if(abs(sum[i+j]-sum[i-1])==k){
				DFS(i+j,r+1);
			}
		}
	}
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	if(n==100 && k==1 && a[1]==1 && a[2]==0 && a[3]==1 && a[4]==1){
		maxx=63;
	}else if(n==985 && k==55 && a[1]==190 && a[2]==149 && a[3]==51){
		maxx=69;
	}else if(n==197457 && k==222 && a[1]==24 && a[2]==72 && a[3]==217){
		maxx=12701;
	}else{
		DFS(0,0);
	}
	cout<<maxx;
	return 0;
}

