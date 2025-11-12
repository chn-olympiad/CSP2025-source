#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005];
int main(){
//	freopen("D:\\xor\\xor5.in","r",stdin);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0) cout<<n/2;
	else if(k==1){
		int ss=0;
		for(int i=1;i<=n;i++)if(a[i]==1)ss++;
		cout<<ss;
	}
	else{
		int t=0,sum=0,tf=1;
		for(int i=1;i<=n;i++){
			t=t^a[i];
			while(t>k) t=t^a[tf],tf++;
			if(t==k) sum++,t=0,tf=i;
		}
		cout<<sum;
	}
	return 0;
}
