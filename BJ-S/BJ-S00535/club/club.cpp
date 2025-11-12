#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
int s[100005][4];
bool cmp(int a[],int b[]){
	int x[4],y[4];
	for (int i=1;i<=3;i++){
		x[i]=a[i];
		y[i]=b[i];
	}
    sort(x+1,x+4);
    sort(y+1,y+4);
    int xb=x[3]-x[2],yb=y[3]-y[2];
    if (xb==yb){
		if (x[3]==y[3]){
			return x[2]>y[2];
		}
		else return x[3]>y[3];
	}
    else return xb>yb;
}
struct sb{
		int v=0;
		int cnt[4]={0,0,0,0};//now choose type cause type's cnt
	} dp[1000005][4];//num,now choose type
sb back;
void Main(){
	int ans=0;
	bool spA=1;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2]>>s[i][3];
        if (s[i][2]!=0||s[i][3]!=0)spA=0;
    }
    int tmp[4];
    for (int j=1;j<n;j++){
		for (int i=1;i<n;i++){
			if (cmp(s[i+1],s[i])){
				tmp[1]=s[i][1];tmp[2]=s[i][2];tmp[3]=s[i][3];
				s[i][1]=s[i+1][1];s[i][2]=s[i+1][2];s[i][3]=s[i+1][3];
				s[i+1][1]=tmp[1];s[i+1][2]=tmp[2];s[i+1][3]=tmp[3];
			}
		}
	}
	if (spA){
		for (int i=1;i<=n/2;i++){
			ans+=s[i][1]+s[i][2]+s[i][3];
		}
		cout<<ans<<endl;
		return;
	}
	for (int i=1;i<=n;i++){//dp[i]
        for (int j=1;j<=3;j++){//now choose type
			dp[i][j]=back;
            for (int q=1;q<=3;q++){//last choose type
				//cout<<'*';
				//if (i==8&&j==3)cout<<'/'<<dp[i-1][q].cnt[j]<<endl;
                if (dp[i-1][q].cnt[j]<n/2){
                    if (dp[i-1][q].v+s[i][j]>dp[i][j].v){
						//cout<<i<<' '<<j<<' '<<q<<endl;
                        dp[i][j].v=dp[i-1][q].v+s[i][j];
						dp[i][j].cnt[1]=dp[i-1][q].cnt[1];
						dp[i][j].cnt[2]=dp[i-1][q].cnt[2];
						dp[i][j].cnt[3]=dp[i-1][q].cnt[3];
                        dp[i][j].cnt[j]=dp[i-1][q].cnt[j]+1;
                    }
                }
                else {
                    dp[i][j].v=dp[i-1][q].v;
					dp[i][j].cnt[1]=dp[i-1][q].cnt[1];
					dp[i][j].cnt[2]=dp[i-1][q].cnt[2];
					dp[i][j].cnt[3]=dp[i-1][q].cnt[3];
				}
            }
        }
    }
    cout<<max(dp[n][1].v,max(dp[n][2].v,dp[n][3].v))<<endl;
    return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while (t--){
        Main();
    }
    return 0;
}
