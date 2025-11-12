#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define int ll
const int mod=1e9+7;
const int N=1e5+50;
#define endl '\n'
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int t;
int n;
int a[N][5]={};
int b[N]={};
string work(int i,int a,int b,int c){
	string ans=to_string(i);
	ans=ans+"#";
	ans=ans+to_string(a);
	ans=ans+'#';
	ans=ans+to_string(b);
	ans=ans+"#";
	ans=ans+to_string(c);
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	IO;
	cin>>t;
	while(t--){
		unordered_map<string,int> dp;
		cin>>n;
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0){
				flag=false;
			}
		}
		if(flag){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1,greater<int>());
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(n<=200){
			string s1=work(1,1,0,0);
			dp[s1]=a[1][1];
			string s2=work(1,0,1,0);
			dp[s2]=a[1][2];
			string s3=work(1,0,0,1);
			dp[s3]=a[1][3];
			//~ cout<<dp[s1]<<" "<<dp[s2]<<" "<<dp[s3]<<endl;
			for(int i=2;i<=n;i++){
				for(int j=0;j<=min(n/2,i);j++){
					for(int k=0;k<=min(i-j,i/2);k++){
						int l=i-j-k;
						if(l>n/2){
							continue;
						}
						string tmp=work(i,j,k,l);
						string tmp1="",tmp2="",tmp3="";
						if(j>=1){
							tmp1=work(i-1,j-1,k,l);
							dp[tmp]=max(dp[tmp],dp[tmp1]+a[i][1]);
						}
						if(k>=1){
							tmp2=work(i-1,j,k-1,l);
							dp[tmp]=max(dp[tmp],dp[tmp2]+a[i][2]);
						}
						if(l>=1){
							tmp3=work(i-1,j,k,l-1);
							dp[tmp]=max(dp[tmp],dp[tmp3]+a[i][3]);
						}
						//~ cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
						//~ cout<<tmp<<" "<<dp[tmp]<<endl;
					}
				}
			}
			int ans=0;
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=min(n-j,n/2);k++){
					int l=n-j-k;
					if(l>n/2){
						continue;
					}
					string s=work(n,j,k,l);
					ans=max(ans,dp[s]);
				}
			}
			cout<<ans<<endl;
		}
	}	
	return 0;
}
