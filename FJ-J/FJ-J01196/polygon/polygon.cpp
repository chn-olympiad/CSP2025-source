#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
void myself(int sum,int step,int maxx){
	
	if(step==0){
		if(sum>maxx*2){
			
			ans++;
		
		}
		return;
	}
	
	myself(sum+a[step],step-1,max(maxx,a[step]));
	myself(sum,step-1,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	myself(0,n,0);
	cout<<ans%998244353;
	return 0;
}
