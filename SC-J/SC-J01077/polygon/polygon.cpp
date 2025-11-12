#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],b[5005];
int ton(int x,int y,int r,int l){
	if(r==l){
		if(x>b[l] && y>=3){
			return 1;
		}else{
			return 0;
		}
	}
	return ton(x+a[r],y+1,r+1,l)+ton(x,y,r+1,l);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]*2;
	}
	long long int ans=0;
	for(int i=3;i<=n;i++){
		 ans+=ton(a[i],1,1,i);
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}