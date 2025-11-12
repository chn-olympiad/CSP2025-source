#include<bits/stdc++.h>
using namespace std;
long long h[5010],n,ans[5010]={0},z,zong=0,cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    z=1;
    for(int i=1;i<=n;i++) cin>>h[i];
    sort(h+1,h+n+1);
    if(n<3){
    	cout<<0;
    	return 0;
	}
    if(n==3){
    	if(h[1]+h[2]>h[3]) cout<<1;
    	else cout<<0;
    	return 0;
	}
    if(h[n]==1){
    	for(int i=3;i<=n;i++){
    		for(int j=0;j<i;j++){
    			z*=(n-j);	
			}
			for(int j=1;j<=i;j++){
				z/=j;
			}
			z%=998244353;
			zong+=z;
			z=1;
		}
		cout<<zong;
		return 0;
	}
    for(int i=1;i<=n;i++) ans[i]=ans[i-1]+h[i];
    for(int i=3;i<=n;i++){
    	for(int j=i-1;j<n;j++){
    		z=j-i+2;
    		zong=ans[j]-ans[z-1];
    		for(int x=n;x>j;x--){
    			if(x<zong){
    				cnt+=x-j;
    				break;
				}
			}
			
		}
	}
	cout<<cnt;
	return 0;
} 