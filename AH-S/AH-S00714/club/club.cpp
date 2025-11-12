#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[4],ans,a[100005][4],cha[4][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		memset(cha,0,sizeof(cha));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			    cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])ans+=a[i][1],cha[1][++cnt[1]]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			else if(a[i][3]<=a[i][2]&&a[i][1]<=a[i][2])ans+=a[i][2],cha[2][++cnt[2]]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			else if(a[i][3]>=a[i][2]&&a[i][1]<=a[i][3])ans+=a[i][3],cha[3][++cnt[3]]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
		}
		if(cnt[1]>n/2){
			sort(cha[1]+1,cha[1]+cnt[1]+1);
			for(int i=1;i<=cnt[1]-n/2;i++)ans-=cha[1][i];
		}
		if(cnt[2]>n/2){
			sort(cha[2]+1,cha[2]+cnt[2]+1);
			for(int i=1;i<=cnt[2]-n/2;i++)ans-=cha[2][i];
		}
		if(cnt[3]>n/2){
			sort(cha[3]+1,cha[3]+cnt[3]+1);
			for(int i=1;i<=cnt[3]-n/2;i++)ans-=cha[3][i];
		}
		cout<<ans<<endl;
	}
	return  0;
}

