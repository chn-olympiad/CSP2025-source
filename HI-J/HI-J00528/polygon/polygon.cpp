#include<bits/stdc++.h>

using namespace std;

int n;
int sum=0;
int stick[5005];

int dfs(int x,int s,int max1){
	if(x==n) return 0;
	if(x>2 && s>max1*2) sum++;
	dfs(x+1,s+stick[x],max(max1,stick[x]));
	dfs(x+1,s,max1);
	return 0;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>stick[i];
	dfs(0,0,0);
	cout<<sum;
	return 0;
}
