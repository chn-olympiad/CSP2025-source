#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,ax=INT_MIN,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		for(int i=1;i<=n;i++){
			sum+=a[i];
			ax=max(ax,a[i]);
		}
		if(sum>ax*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		for(int i=1;i<=n;i++){
		    for(int k=3;k<=n;k++){
		    	for(int j=i;j<=k;j++){
		    		sum+=a[i];
		    		ax=max(ax,a[i]);
				}
			}if(ax<=1){
    		    if(sum>ax*2){
    		    	cnt++;
				}
		    }
    	}
    	cout<<cnt;
	}
	
	return 0;
}
