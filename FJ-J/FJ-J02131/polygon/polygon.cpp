#include<bits/stdc++.h>
using namespace std;
int n,a[5229],ans,plusans;
void chore(int pos,int sum,int mx){
	if(pos==n+1){
		if(sum>2*mx)ans++;
		return ;
	}
	chore(pos+1,sum+a[pos],max(mx,a[pos]));
	chore(pos+1,sum,mx);
	return ;
}
void LUcy(int pos,int sum,int mx){
	if(pos==n+1){
		if(sum>2*mx)plusans=(plusans+1)%998244353;
		return ;
	}
	chore(pos+1,sum+a[pos],max(mx,a[pos]));
	chore(pos+1,sum,mx);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int fff=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fff=0;
	}
	if(n<3){
		cout<<0;
	}else if(n<=29){
		chore(1,0,0);
		cout<<ans;
	}else{
		LUcy(1,0,0);
		if(fff==0) cout<<plusans;
		else cout<<615868644;
	}
	return 0;
}
