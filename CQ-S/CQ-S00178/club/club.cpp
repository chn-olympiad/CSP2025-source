#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[100100][10];
int anow,bnow,cnow;
int n;
int ans=-1;
void dfs(int now,int num){
	if(anow>n/2||bnow>n/2||cnow>n/2)return;
	if(now>n){
		ans=max(ans,num);	
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1)anow++;
		if(i==2)bnow++;
		if(i==3)cnow++;
		dfs(now+1,num+arr[now][i]);
		if(i==1)anow--;
		if(i==2)bnow--;
		if(i==3)cnow--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=-1;
		anow=bnow=cnow=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>arr[i][j];
			}
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

