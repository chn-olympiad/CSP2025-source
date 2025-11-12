#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005][5];
int dp[10][10005];
int ansn;
void dfs(int s,int num1,int num2,int num3,int ans){
	if(num1>n/2||num2>n/2||num3>n/2) return ;
	if(s>n){
		ansn=max(ansn,ans);
		
		
		return ;
	}
	
	dfs(s+1,num1+1,num2,num3,ans+a[s][1]);
	dfs(s+1,num1,num2+1,num3,ans+a[s][2]);
	dfs(s+1,num1,num2,num3+1,ans+a[s][3]);
	
}

void cz(){
	cin >>n;
	ansn=0;
	int f=0;
	for(int i=1;i<=n;i++){
		cin >>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]||a[i][3]) f=1;
	}
	if(f==0){
	//	cout <<1<<endl;
		int anss[10005];
		for(int i=1;i<=n;i++){
			anss[i]=a[i][1];
		}
		sort(anss+1,anss+n+1);
		for(int i=n/2+1;i<=n;i++){
			ansn+=anss[i];
		}
		cout <<ansn;
		return ;
	}
	dfs(1,0,0,0,0);
	cout <<ansn<<endl;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		cz();
	}
	return 0;
}
