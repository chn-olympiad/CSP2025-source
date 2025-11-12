#include<bits/stdc++.h>
using namespace std;
int n,a[100100],b[100100],c[100100];
int cnt = 0;
void dfs(int kep,int s1,int s2,int s3,int ans){
	if(kep > n){
		cnt = max(cnt,ans);
		return;
	}
	for(int i = 1;i <= 3;i++){
		if(i == 1 && s1 < (n / 2)){
			dfs(kep + 1,s1 + 1,s2,s3,ans + a[kep]);
		}
		if(i == 2 && s2 < (n / 2)){
			dfs(kep + 1,s1,s2 + 1,s3,ans + b[kep]);
		}
		if(i == 3 && s3 < (n / 2)){
			dfs(kep + 1,s1,s2,s3 + 1,ans + c[kep]);
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cnt = 0;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1,0,0,0,0);
		cout<<cnt<<endl;
	}
	return 0;
}
