#include<iostream>
using namespace std;
int n,a[5010],ans,mod=998244353;
void find(int k,int x,int sum,int maxx){
	if(k>=3&&sum>2*maxx)ans++;
	//cout<<k<<' '<<x<<' '<<sum<<' '<<maxx<<' '<<ans<<endl;
	ans%=mod;
	for(int i=x+1;i<=n;i++){
		find(k+1,i,sum+a[i],max(a[i],maxx));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		find(1,i,a[i],a[i]);
	}
	cout<<ans;
}
