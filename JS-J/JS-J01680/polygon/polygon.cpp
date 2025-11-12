#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool flag=true;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)flag=false;
	}
	if(n==3){
		int ss=a[0]+a[1]+a[2];
		int maxn=max(a[0],a[1]);
		maxn=max(maxn,a[2]);
		if(ss>2*maxn)cout<<1;
		else cout<<0;
		return 0;
	}else if(n<3){
		cout<<0;
		return 0;
	}
	long long ans=0;
	if(flag){
		for(int i=3;i<=n;i++){
			long long cnt=1,sum=1;
			for(int j=0;j<i;j++){
				cnt=cnt*(n-j);
				sum=sum*(j+1);
			}
			ans+=cnt/sum;
		}
		cout<<ans%998%244%353;
		return 0;
	}
	
	return 0;
}
