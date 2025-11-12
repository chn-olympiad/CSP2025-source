#include<bits/stdc++.h>
using namespace std;
int Min[100005];
int a1[100005],a2[100005],a3[100005];
int n;
int ans=0;
int b[4];
void dfs(int now,int sum){
	if(now==n){
		ans=max(ans,sum);
		return ;
	}else{
		for(int j=1;j<=3;j++){
			if(b[j]==n/2) continue;
			b[j]++;
			now++;
			if(j==1) sum+=a1[now];
			if(j==2) sum+=a2[now];
			if(j==3) sum+=a3[now];
//			cout<<now<<' '<<j<<" "<<sum<<endl;
			dfs(now,sum);
			now--;
			if(j==1) sum-=a1[now+1];
			if(j==2) sum-=a2[now+1];
			if(j==3) sum-=a3[now+1];
			b[j]--;
		}
	}
}
struct Club{
	int id,num;
};
Club k[100005];
bool cmp(const Club A,const Club B){
	return A.num>B.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(b,0,sizeof(b));
		ans=0;
		cin>>n;
		int b2=0,b3=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]==0) b2++;
			if(a3[i]==0) b3++;
		}
		if(b2==n&&b3==n){
			sort(a1+1,a1+n+1);
			for(int i=n;i>=n/2;i--){
				ans+=a1[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(b3==n&&b2!=n){
			for(int i=1;i<=n;i++){
				k[i].id=i;
				k[i].num=a1[i]-a2[i];
			}
			sort(k+1,k+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a1[k[i].id];
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a1[k[i].id]-k[i].num;
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}