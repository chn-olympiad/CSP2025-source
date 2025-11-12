#include<bits/stdc++.h>
using namespace std;
long long number[5005];
long long pow2[5005];
long long hzh[5005];
bool tmp(int a,int b){
	return a>b;
}
void pow_2(){
	int now=1;
	for(int i=0;i<5003;i++){
		pow2[i]=now;
		now*=2;
		now%=998244353;
	}
	return;
}
int n;
long long ans=0;
void dfs(int now_i,long long now_num,long long now_max){
	cout<<now_i<<endl;
	if(now_num>2*now_max){
		ans+=pow2[n-now_i];
		ans%=998244353;
		return;
	}
	for(int i=now_i+1;i<=n;i++){
		if(now_num+hzh[i]<=2*now_max){
			break;
		}
		dfs(i,now_num+number[i],max(now_max,number[i]));
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	pow_2();
	for(int i=1;i<=n;i++){
		cin>>number[i];
	}
	sort(number+1,number+n+1,tmp);
	hzh[n]=number[n];
	for(int i=n-1;i>=1;i--){
		hzh[i]=hzh[i+1]+number[i];
	} 
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
