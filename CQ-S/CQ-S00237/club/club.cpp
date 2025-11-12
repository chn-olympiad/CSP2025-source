#include<bits/stdc++.h>
using namespace std;
long long dp[2][305][305][305],vr[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		int v;
		cin>>v;
		for(int a=0;a<=v/2;a++){
			for(int b=0;b<=v/2;b++){
				for(int c=0;c<=v/2;c++){
					dp[0][a][b][c]=0;
					dp[1][a][b][c]=0;
				}
			}
		}
		for(int i=1;i<=v;i++) cin>>vr[i][1]>>vr[i][2]>>vr[i][3];
//		cout<<"cin end"<<endl;
		long long ans=-1e18;
		for(int i=1;i<=v;i++){
//			cout<<"i="<<i<<endl;//ts 
			for(int a=0;a<=v/2;a++){
//				cout<<"a="<<a<<endl;//ts
				for(int b=0;b<=v/2;b++){
//					cout<<"b="<<b<<endl;//ts
					int c=i-a-b;
					if(c<0 || c>v/2 || a+b+c>v) continue;
//					cout<<"c="<<c<<" ";//ts
//					cout<<"from: ";
					if(a>0){
						dp[1][a][b][c]=max(dp[1][a][b][c],dp[0][a-1][b][c]+vr[i][1]);
//						cout<<"a-1 . "<<dp[0][a-1][b][c]+vr[i][1]<<' ';
//						cout<<"and"<<' ';
					}
					if(b>0){
						dp[1][a][b][c]=max(dp[1][a][b][c],dp[0][a][b-1][c]+vr[i][2]);
//						cout<<"b-1 . "<<dp[0][a][b-1][c]+vr[i][2]<<' ';
//						cout<<"and"<<' ';
					}
					if(c>0){
						dp[1][a][b][c]=max(dp[1][a][b][c],dp[0][a][b][c-1]+vr[i][3]);
//						cout<<"c-1 . "<<dp[0][a][b][c-1]+vr[i][3]<<' ';
					}
//					cout<<" so dp="<<dp[1][a][b][c]<<endl;//ts
					if(i==v) ans=max(ans,dp[1][a][b][c]);
				}
			} 
			for(int a=0;a<=v/2;a++){
				for(int b=0;b<=v/2;b++){
					int c=i-a-b;
					if(c<0 || c>v/2) continue;
					dp[0][a][b][c]=dp[1][a][b][c];
					dp[1][a][b][c]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

