#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[100005][5];
void dg(int n,int sum,int now,int s1,int s2,int s3){
	if(now==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(s1<n/2)dg(n,sum+a[now][1],now+1,s1+1,s2,s3);
	if(s2<n/2)dg(n,sum+a[now][2],now+1,s1,s2+1,s3);
	if(s3<n/2)dg(n,sum+a[now][3],now+1,s1,s2,s3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dg(n,0,1,0,0,0);
		cout<<ans<<"\n";
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
