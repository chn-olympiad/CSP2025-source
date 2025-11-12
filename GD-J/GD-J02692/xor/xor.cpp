#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long num[N],qi[N];
long long dp[N];
long long n,m;
map<int,int>mp;
void so3(){
	for(int i=  1;i<=n;i++){
		mp[qi[i]^m]=i;
		dp[i]=max(dp[i],dp[i-1]);
		int j = mp[qi[i]];
		if((qi[j]^qi[i])==m){
			dp[i]=max(dp[i],dp[j]+1);
		}
	}
	cout<<dp[n];
}
int chu[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int flag=0,cnt=0;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>num[i];
		if(chu[num[i]]>=1){
			cnt++;
			chu[num[i]]=0;
		}else{
			chu[num[i]]++;
		}
		if(num[i]==0){
			cnt++;
		}
		qi[i]=num[i]^qi[i-1];
		
	}
	if(m==0){
		cout<<cnt;
	}
	else so3();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
