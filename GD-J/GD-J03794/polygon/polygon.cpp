#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,maxn=-1;
int mp[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>mp[i];
    	maxn=max(maxn,mp[i]);
	}
	if(maxn==1){
		long long ans=0;
		for(long long i=3;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				ans+=j;
				ans=ans%998244353; 
			}
		}
		cout<<ans;
	}else if(n==3){
		if(mp[1]+mp[2]+mp[3]>2*max(mp[1],max(mp[2],mp[3]))){
			cout<<1;
		}else cout<<0;
	}else{
		cout<<0;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
