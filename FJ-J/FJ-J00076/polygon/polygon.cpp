#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,a[5005],ans;
struct nn{
	int sum,mx,cnt;
};
vector<nn> dp[5005];

//FUCKYOU CCF
//FUCKYOU CSP
//FUCKYOU NOI
//FUCKYOU CSP/J-2025 T4 polygon
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	dp[0].push_back({0,-1,0});
	for(int i=1;i<=n;i++){
		for(auto j:dp[i-1]){
			dp[i].push_back(j);
			dp[i].push_back({j.sum+a[i],max(j.mx,a[i]),j.cnt+1});
		}
	}
	for(auto i:dp[n])if(i.sum>i.mx*2&&i.cnt>=3)ans++;
	cout<<ans;
	fclose(stdin);fclose(stdout);
}

