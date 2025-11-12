#include<bits/stdc++.h>
using namespace std;
#define ll long long

int maxf(int a,int b,int c){
	if(a>b&&a>c)return a;
	else if(b>a&&b>c)return b;
	else if(c>b&&c>a) return c;
}

bool c(int a,int b){
	return a>b;
}
int a[100005][3];
int dp[100005][3];
int b[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		int n;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(b,0,sizeof(b));
		int w[3];
		cin>>n;
		for(int i=0;i<3;i++){
			w[i]=n/2;
		}
		
		int a2=0,a3=0;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			a2+=a[i][1];
			a3+=a[i][2];
			b[i]=a[i][0];
			//cout<<1<<endl;
		}
		if(a2==0&&a3==0){
			sort(b,b+n+1,c);
			int ans1=0;
			for(int ii=0;ii<n/2;ii++){
				ans1+=b[ii];
			}
			cout<<ans1<<endl;
			t--;
			continue;
			
		}
		for(int i=0;i<3;i++){
			dp[0][i]=a[0][i];
			if(a[0][i]==maxf(a[0][0],a[0][1],a[0][2])){
				w[i]--;
			}
		}
		for(int i=1;i<=n;i++){
			
			for(int j=0;j<3;j++){
				int m1=0,m2=0,m3=0;
				//cout<<w[0]<<endl;
				if(w[0]>0)m1=dp[i-1][0]+a[i][j];else m1=dp[i-1][0];
				if(w[1]>0)m2=dp[i-1][1]+a[i][j];else m2=dp[i-1][1];
				if(w[2]>0)m3=dp[i-1][2]+a[i][j];else m3=dp[i-1][2];
				if(j==0&&w[0]<=0){
				
					if(m2>m1&&m2>m3){
						w[0]++;
						w[1]--;
						dp[i][j]=m2;
					}
					else if(m3>m1&&m3>m2){
						w[0]++;
						w[2]--;
						dp[i][j]=m3;
					}	
				}
				else if(j==1&&w[1]<=0){
					if(m1>m2&&m1>m3){
						w[1]++;
						w[0]--;
						dp[i][j]=m1;
					}
					else if(m3>m1&&m3>m2){
						w[1]++;
						w[2]--;
						dp[i][j]=m3;
					}
				}
				else if(j==2&&w[2]<=0){
					if(m1>m2&&m1>m3){
						w[2]++;
						w[0]--;
						dp[i][j]=m1;
					}
					else if(m2>m1&&m2>m3){
						w[2]++;
						w[1]--;
						dp[i][j]=m2;
					}
				}
				else dp[i][j]=maxf(m1,m2,m3);		
				
			}
			int max2=maxf(dp[i][0],dp[i][1],dp[i][2]);
			if(max2==dp[i][0])w[0]--;
			else if(max2==dp[i][1])w[1]--;
			else if(max2==dp[i][2])w[2]--;
		}
		//cout<<endl;
		//for(int i=0;i<=5;i++){
		//	cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;	
		//} 
		cout<<maxf(dp[n][0],dp[n][1],dp[n][2])<<endl;
		t--;
	}
	return 0;
}

