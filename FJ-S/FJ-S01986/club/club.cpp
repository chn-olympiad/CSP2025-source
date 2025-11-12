#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,a[100005][5],ans;
long long sum[10],num[10][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof a);
		memset(sum,0,sizeof sum);
		memset(num,0,sizeof num);
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) sum[1]++,num[1][sum[1]]=a[i][1]-max(a[i][2],a[i][3]),ans+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) sum[2]++,num[2][sum[2]]=a[i][2]-max(a[i][1],a[i][3]),ans+=a[i][2];
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) sum[3]++,num[3][sum[3]]=a[i][3]-max(a[i][1],a[i][2]),ans+=a[i][3];
		}
		sort(num[1]+1,num[1]+sum[1]+1);
		sort(num[2]+1,num[2]+sum[2]+1);
		sort(num[3]+1,num[3]+sum[3]+1);
		int now=1;
		while(sum[1]>n/2){
			ans-=num[1][now];
			sum[1]--;
			now++;
		}
		now=1;
		while(sum[2]>n/2){
			ans-=num[2][now];
			sum[2]--;
			now++;
		}
		now=1;
		while(sum[3]>n/2){
			ans-=num[3][now];
			sum[3]--;
			now++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
