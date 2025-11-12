#include<bits/stdc++.h>
using namespace std;
int n,stick[5001],dp[5001],cnt=0;
void shape(int l,int r){//x为下标 
	if(l==n+1||r==n+1){
		return;
	}
	shape(l,r+1);
	shape(l+1,r);
	cout<<"和大于最大值的两倍吗？"<<endl;
	if(dp[r]-dp[l-1]>2*stick[r]){
		cout<<"是"<<endl; 
		cnt++;
	}else cout<<"否"<<endl;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stick[i];
	}sort(stick,stick+n);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+stick[i];
	}
	shape(0,0);
	cout<<cnt;
	return 0;
}
