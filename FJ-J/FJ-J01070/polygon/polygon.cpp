#include<bits/stdc++.h>
using namespace std;


long long n,ans=0;
int a[5005];
bool flag[5005];

void dfs(int k,int maxnum,int sum,int step){
	if(k==0 || step>n){
		if(k==0 && sum>maxnum*2){
			//cout<<sum<<" "<<maxnum<<endl;
			ans++;
			
		}
		return ;
	}
	
	for(int i=step;i<=n;i++){
		
		dfs(k-1,max(maxnum,a[i]),sum+a[i],i+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	
	for(int i=3;i<=n;i++){
		dfs(i,0,0,1);
	}
	
	cout<<ans;
	
	
	
	
	
	return 0;
} 
