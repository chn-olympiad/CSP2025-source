#include<bits/stdc++.h>
using namespace std;
int t;
int n;
typedef struct st{
	int a,b,c;
}st;
st wo[100005];
bool cmp(st num1,st num2){
	return num1.b>num2.b;
}
int main(){
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
	cin>>t;
	int ans;
	while(t--){
		cin>>n;
		ans=0;
		int flag=-1;
		for(int i=1;i<=n;i++){
			cin>>wo[i].a>>wo[i].b>>wo[i].c;
			if(wo[i].a==0&&wo[i].c==0&&flag==-1){
				flag=0;
			}else if(wo[i].c==0&&flag<=0){
				flag=1;
			}else{
				flag=2;
			}
		}
		if(flag==0){
			sort(wo+1,wo+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=wo[i].b;
			}
		}else{
			int dp[100005],temp;
			fill(dp,dp+n+1,0);
			int cnt[5]={0,0,0,0,0};
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n/2&&j<=i;j++){
					for(int k=1;k<=3;k++){
						if(k==1)temp=worker[i].a;
						if(k==2)temp=worker[i].b;
						if(k==3)temp=worker[i].c;
						dp[i]=max(dp[i],dp[i-j]+temp);
					}
				}
			}
			ans=dp[n];
		}
		cout<<ans<<endl;
	}
        return 0;
} 
