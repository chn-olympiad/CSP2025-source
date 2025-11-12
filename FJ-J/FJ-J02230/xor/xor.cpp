#include<bits/stdc++.h>
using namespace std;
int n,k,ans,dp=-1,l,r;
int a[500005],v[500005]; 
int yh(int x,int y){
	int ans;
	while(x!=0||y!=0){
		ans*=10;
		if(x%10!=y%2&&(x%10==1||y%2==1))++ans;
		x/=10,y/=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++,v[i]=i;
		}
	}
	for(int o=2;o<=n;o++){
		for(int i=1;i<=n;i++){
			if(v[i]!=0){
				i=v[i]+1,dp=-1,r=0;continue;
			}
			if(dp==-1){
				dp=a[i],l=i;
			}
			else dp=yh(dp,a[i]);
			r++;
			if(r==o&&dp==k){
				++ans,dp=-1,v[l]=i,r=0;
			}
			if(r>o){
				i-=o-1,dp=-1,r=0;
			}
	    }	
	}
	cout<<ans;
	return 0;
}
