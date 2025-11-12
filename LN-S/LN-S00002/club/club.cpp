#include <iostream>
using namespace std;
//常量
const int N=1e5+101;
//第一个数据n
int _g;
//其他value
int n,s[N][3],dp[N][3],c[3],k1,k2,con;
int main(){
	//文件处理
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//多个测试数据
	cin>>_g;
	for(int whyThese=0;whyThese<_g;whyThese++){
		//输入
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][0]>>s[i][1]>>s[i][2];
		}
		//dp
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				if(c[j]<n/2){
					dp[i][j]=k1+s[i][j];
				}else{
					dp[i][j]=k2+s[i][j];
					c[con]--;
					c[j]++;
				}
			}
			k1=0;
			k2=0;
			//第一大数值
			for(int j=0;j<3;j++){
				if(k1<dp[i][j]){
					k1=dp[i][j];
					con=j;
					
				}
			}c[con]++;
			//第二大数值
			for(int j=0;j<3;j++){
				if(k2<dp[i][j]&&con!=j){
					k2=dp[i][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		int ans=0;
		for(int i=0;i<3;i++){
			ans=max(ans,dp[n][i]);
		}
		for(int i=1;i<=n;i++){
			s[i][0]=s[i][1]=s[i][2]=0;
			dp[i][0]=dp[i][1]=dp[i][2]=0;
			k1=k2=0;
			c[0]=c[1]=c[2]=0;
			con=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
