#include<bits/stdc++.h>
using namespace std;
long long t,n,i,ma,k,j,ans,ans1,ans2,ans3,ma1,z;
long long cnt[4]={0};
struct A{
	long long x;
}a[100010][4];
void dfs(long long l,long long r){
	if(cnt[1]<k){ans+=a[l+1][1].x;cnt[1]++;dfs(l+1,1);}
	else if(cnt[2]<k){ans+=a[l+1][2].x;cnt[2]++;dfs(l+1,2);}
	else if(cnt[3]<k){ans+=a[l+1][3].x;cnt[3]++;dfs(l+1,3);}
	if(l==n)return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>n;
		k=n/2;	
		for(j=1;j<=n;j++)cin>>a[j][1].x>>a[j][2].x>>a[j][3].x;
		ans=a[1][1].x;
		cnt[1]=1;cnt[2]=0;cnt[3]=0;
		dfs(1,1);ans1=ans;
		ans=a[1][2].x;
		cnt[1]=0;cnt[2]=1;cnt[3]=0;
		dfs(1,2);ans2=ans;
		ans=a[1][3].x;
		cnt[1]=0;cnt[2]=0;cnt[3]=1;
		dfs(1,3);ans3=ans;
		if(ans1<ans2)swap(ans1,ans2);
		if(ans1<ans3)swap(ans1,ans3);
		if(ans2<ans3)swap(ans2,ans3);
		cout<<ans1<<endl;
	}
	return 0;
}
