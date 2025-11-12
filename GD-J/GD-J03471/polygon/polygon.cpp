#include<bits/stdc++.h>
using namespace std;

int n,ans=0;
vector<int> a;

void dfs(int sum,int pre_i,int use){
	if(sum>a[pre_i]*2&&use>3){
		ans++;
	}
	for(int i=0;i<n;i++){
		if(pre_i<i){	
			dfs(sum+a[i],i,use+1);
			dfs(sum+a[i]-a[pre_i],i,use);	
			}		
		}
	}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	a.resize(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(1,0,1);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
