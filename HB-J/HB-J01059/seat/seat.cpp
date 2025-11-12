#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,sum[105],ans,cnt,ans1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
	    cin>>sum[i];	
	}
	ans=sum[1];
	sort(sum+1,sum+1+n*m);
	for(int i=1;i<=n*m;i++){
	    if(ans==sum[i]){
		    ans=n*m-i+1;
		    break;	
		}	
	}
	cnt=ans/n;
	ans1=ans;
	ans=ans%n;
	if(ans1==n){
	    cout<<1<<" "<<n;	
	}
	else if(cnt%2==0){
	    cout<<cnt+1<<" "<<ans;
	}
	else{
	    cout<<cnt+1<<" "<<n-ans+1;	
	}
    return 0;
}
