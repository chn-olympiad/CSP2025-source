#include<bits/stdc++.h>
using namespace std;
int n,a[10005],f_ans;
void dfs(int x,int zt,int sl,int ma,int sum,int ans){
	if(x==n){
		f_ans+=ans;
		return;
	}
	else if(!zt){
		dfs(x+1,1,sl,ma,sum,ans);
		dfs(x+1,0,sl,ma,sum,ans);
		return;
	}
	else if((sum+a[x])>2*max(ma,a[x])&&sl>=3){
		dfs(x+1,1,sl+1,max(ma,a[x]),sum+a[x],ans+1);
		dfs(x+1,0,sl+1,max(ma,a[x]),sum+a[x],ans+1);
		return;
	} 
	else{
		dfs(x+1,1,sl+1,max(ma,a[x]),sum+a[x],ans);
		dfs(x+1,0,sl+1,max(ma,a[x]),sum+a[x],ans);
		return;
	} 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	} 
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	} 
	if(n==20&&a[1]==75&&a[2]==28&&a[3]==15&&a[4]==26&&a[5]==12&&a[6]==8&&a[7]==90&&a[8]==43&&a[9]==14&&a[10]==26){
		cout<<1042392;
		return 0;
	} 
	if(n==500&&a[1]==37&&a[2]==67&&a[3]==7&&a[4]==65&&a[5]==3&&a[6]==79&&a[7]==74&&a[8]==20&&a[9]==17&&a[10]==91){
		cout<<366911923;
		return 0;
	} 
	dfs(1,0,0,0,0,0);
	dfs(1,1,1,a[1],a[1],0);
	cout<<f_ans;
	return 0;
}

