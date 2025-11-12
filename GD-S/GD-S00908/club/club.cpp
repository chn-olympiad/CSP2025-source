#include<bits/stdc++.h>
using namespace std;
int t,n,ans,dp[100005];
bool flag1,flag2,flag3,flag;
struct co{
	int s1,s2,s3;
}a[100005];

bool cmp1(co b,co c){
	return b.s1>c.s1;
}
bool cmp2(co b,co c){
	return b.s2>c.s2;
}
bool cmp3(co b,co c){
	return b.s3>c.s3;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		flag=flag1=flag2=flag3=0;
		cin>>n;
		ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			
			if(a[i].s2!=0||a[i].s3!=0){flag1=1;}
			if(a[i].s1!=0||a[i].s3!=0){flag2=1;}
			if(a[i].s1!=0||a[i].s2!=0){flag3=1;}
			if(a[i].s2!=0||a[i].s3!=0||a[i].s1!=0){flag=1;}
		}
		if(n==2){
			ans=a[1].s1+a[2].s2;
			ans=max(ans,a[1].s1+a[2].s3);ans=max(ans,a[1].s2+a[2].s1);
			ans=max(ans,a[1].s2+a[2].s3);ans=max(ans,a[1].s3+a[2].s2);
			ans=max(ans,a[1].s3+a[2].s1);
			cout<<ans<<endl;
			continue;
		}else if(!flag1){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].s1;
			}
			cout<<ans<<endl;
			continue;
		}else if(!flag2){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].s2;
			}
			cout<<ans<<endl;
			continue;
		}else if(!flag3){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].s3;
			}
			cout<<ans<<endl;
			continue;
		}else if(!flag){
			cout<<"0";
			continue;
		}else{
			for(int i=1;i<=n;i++){
				dp[i]=dp[i-1]+max(a[i].s1,max(a[i].s2,a[i].s3)); 
			}
			cout<<dp[n]<<endl;
			continue;
		}
	}
	return 0;
}
