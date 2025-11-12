#include<bits/stdc++.h>
using namespace std;

long long anss;
int t,n;
int a[100005][4];
int x[4];

void dfs(int i,long long ans){
	if(i>n){
		for(int j=1;j<=3;j++){
			if(x[j]>n/2) return;
		}
		anss=max(anss,ans);
		return;
	}
	for(int j=1;j<=3;j++){
		ans+=a[i][j];
		x[j]++;
		dfs(i+1,ans);
		x[j]--;
		ans-=a[i][j];
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<anss<<"\n";
		anss=0;
		memset(x,0,sizeof(0));
	}
return 0;
}
