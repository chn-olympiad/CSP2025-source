#include<bits/stdc++.h>

using namespace std;

int dp[1<<18][20],n,ans,c[20],m;
string s;

int count(int k){
	int num=0;
	while(k){
		if(k&1) num++;
		k>>=1;
	}
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	
	cin>>s;
	
	for(int i=1;i<=n;i++)
		cin>>c[i];
		
	dp[0][0]=1;
	
	for(int i=1;i<=1<<n-1;i++)
		for(int j=1;j<=n;j++)
			if(i&(1<<j-1)){
				
				for(int k=0;k<count(i);k++){
					if(count(i)-k>=c[i])	dp[i][k]+=dp[i&(1<<j-1)][k];
					else{
						if(s[count(i)-1]='1')
							dp[i][k+1]+=dp[i&(1<<j-1)][k];
						else
							dp[i][k]+=dp[i&(1<<j-1)][k];
					}
				}
			}
	
	for(int i=m;i<=n;i++)
		ans+=dp[1<<n-1][i];
		
	cout<<ans<<endl;
	
	return 0;
} 
