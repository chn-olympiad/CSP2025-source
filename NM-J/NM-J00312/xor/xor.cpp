#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,res[N],arr[N],large=-1,da,shu,ans1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0,x;i<n;i++)cin>>arr[i],da=max(da,arr[i]),shu+=(arr[i]==1?1:0);
    if(da==1&&shu==n){
    	if(k==1){
		for(int i=1;i<n;i+=2)ans1+=n-i+1;
    	cout<<ans1;}else if(k==0){
    		for(int i=2;i<n;i+=2)ans1+=n-i+1;
    		cout<<ans1;
		}
	}
	else{
	
	int flag=large+1;
    while(flag<n){
        int i=flag,xr=arr[i],ans=res[flag];
        for(int j=i+1;j<n;j++){
            if(xr==k){
                ans++,i=j,xr=arr[i],res[j]=max(res[j],ans);
            }else
                xr^=arr[j];
        }
        if(xr==k)ans++;
        flag++,res[n-1]=max(res[n-1],ans);
    }
    cout<<res[n-1];
	}
}
