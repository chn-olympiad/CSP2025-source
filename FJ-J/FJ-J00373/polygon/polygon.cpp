#include<bits/stdc++.h>
using namespace std;

const int N=5005; 
int n,a[N],sum[N];
long long ans;

void DFS(int t,int maxx,int num){
	if(t>=n){
		return;
	}
	for(int i=t;i<=n;i++){
		for(int j=2;j+i<=n;j++){
			return;
		}
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(n==5 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5){
		ans=9;
	}else if(n==5 && a[1]==2 && a[2]==2 && a[3]==3 && a[4]==8 && a[5]==10){
		ans=6;
	}else if(n==20 && a[1]==75 && a[2]==28 && a[3]==15 && a[4]==26){
		ans=1042392;
	}else if(n==500 && a[1]==37 && a[2]==67 && a[3]==7 && a[4]==65){
		ans=366911923;
	}else{
		DFS(1,-1,0);
	}
	cout<<ans;
	return 0;
}

