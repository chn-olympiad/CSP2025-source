#include<bits/stdc++.h>
using namespace std;
int n,a[5010]={0},ans=0;
int main(){
	freoprn("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	int b=0,maxn,sum,sum1;
	while(b<=(1<<(n-1))){
		maxn=-1;
		sum=0;
		sum1=0;
		b++;
		for(int i=1;i<=n;i++){
			if((i&b)!=0){
				if(a[i]>maxn){
					maxn=a[i];	
				}
				sum+=a[i];
				sum1++;
			}
		}
		if(sum>=(maxn*2) && sum1>=3){
			ans=(ans+1)%998244353;
		}
	}
	cout<<ans;
	return 0;
}
