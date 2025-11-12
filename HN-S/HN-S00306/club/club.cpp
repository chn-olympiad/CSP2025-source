#include<bits/stdc++.h>
using namespace std;
long long n,a[100005][3],dp[100005],pd[100005],t,flag,sun4;

long long s[3][100005];

bool cmp(int x,int y){
	return x<y;
}
void find(int x,int y){
	
}
int main(){
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int flag=0;
		memset(dp,0,sizeof(dp));
		memset(s,0,sizeof(s));
		memset(pd,0,sizeof(pd));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			
			int j;
			if(a[i][0]>a[i][1]){
				if(a[i][0]>a[i][2]) j=0;
				else j=2;
			}
			else if(a[i][1]>a[i][2]) j=1;
			else j=2;
			
			if(j==0) sun4=a[i][0]-max(a[i][1],a[i][2]);
			else if(j==1) sun4=a[i][1]-max(a[i][0],a[i][2]);
			else sun4=a[i][2]-max(a[i][0],a[i][1]);
			//cout<<sun4<<" "<<j<<'\n';
			if(pd[j]>=n/2){
				
				sort(s[j]+1,s[j]+1+pd[j],cmp);
				
				//for(int k=1;k<=pd[j];k++) cout<<s[j][k]<<' ';
				//cout<<'\n';
				//cout<<a[i][j]<<'\n';
				//cout<<sun4<<" "<<s[j][i]<<" "<<j<<'\n';
				if(s[j][1]<sun4){
					dp[i]=dp[i-1]-s[j][1]+a[i][j];
					s[j][1]=sun4;
					//cout<<1;
				}
					
				else{
					dp[i]=dp[i-1]+a[i][j]-sun4;
				}
			}
			
			else{
				dp[i]=dp[i-1]+a[i][j];
				pd[j]++;
				s[j][pd[j]]=sun4;
				//cout<<s[j][pd[j]]<<' ';
			}
			//cout<<dp[i]<<' ';
		}
		
		/*for(int i=0;i<=2;i++){
			for(int j=1;j<=pd[i];j++) cout<<s[i][j]<<' ';
			cout<<'\n';
		}*/
		//cout<<pd[1]<<'\n';
		cout<<dp[n]<<'\n';
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}//Ren5Jie4Di4Ling5%
