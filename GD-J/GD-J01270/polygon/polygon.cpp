#include<bits/stdc++.h>
using namespace std;
int n,l[1000001],lq[1000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		lq[0]=a[0];
		lq[i]+=l[i]+lq[i-1];
	}
	if(n==3){
		if(a[n-1]*2<lq[n-1]) cout<<1;
		else cout<<0;
		return 0;
	}
	
	if(a[n-1]==1){
		int ans=0,bd=1;
		for(int i=3;i<=n;i++){
			int c=n-i;
			while(c++){
				bd*=c;
				if(c==n){
					break;
				}
			}
			ans+=bd;
		}
		cout<<ans;
	}
	int ans=0;
}//出的啥这是 
