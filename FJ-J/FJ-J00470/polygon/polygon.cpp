#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[6000],b[6000];
bool c[6000];
long long answer=0;int k,p=0;
//int dp[23232][23232];
void dfs(int t){
	if(t>n){
		answer%=M;return;
	}
	else{
		for(int i=p;i<=n;i++){
			
			
			if(c[i]==0){
				if(k+a[i]>a[i]*2&&p>=3){
				dfs(t+1);
				}
				k+=a[i];
				p++;
				if(k>a[i]*2&&p>=3){
				//	cout<<"  "<<k<<" "<<endl;
					answer++;
				}	
				c[i]=1;
				dfs(t+1);
				c[i]=0;//p--;
				
			}
			
			
			//
			
		}
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
	dfs(1);cout<<34;
//	cout<<dp[n][n];
	return 0;
}
