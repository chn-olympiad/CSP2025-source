#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=2e5+10;

int n,T,a1[N],a2[N],a3[N],f[N];

inline void solve(){
	cin>>n;
	
	int s1,s2,s3;
	s1=s2=s3=0;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
		if(a1[i]>=a2[i]&&a1[i]>=a3[i])s1++;
		if(a2[i]>=a1[i]&&a2[i]>=a3[i])s2++;
		if(a3[i]>=a1[i]&&a3[i]>=a2[i])s3++;
	}
	
	int ans1,ans2,ans3;
	ans1=ans2=ans3=0;
	for(int i=1;i<=n;i++)
		ans3+=max(a1[i],max(a2[i],a3[i]));
	ans1=ans2=ans3;
	
	if(s1<=n/2&&s2<=n/2&&s3<=n/2){
		cout<<ans1<<"\n";
		return;
	}
	
	if(s1>=n/2){
		if(s1>n/2){
			int c=0;
			for(int i=1;i<=n;i++)
				if(a1[i]>=a2[i]&&a1[i]>=a3[i])
					f[++c]=a1[i]-max(a2[i],a3[i]);
			sort(f+1,f+c+1);
			for(int i=1;i<=s1-(n/2);i++)ans1-=f[i];
		}
	}else ans1=0;
	
	if(s2>=n/2){
		if(s2>n/2){
			int c=0;
			for(int i=1;i<=n;i++)
				if(a2[i]>=a1[i]&&a2[i]>=a3[i])
					f[++c]=a2[i]-max(a1[i],a3[i]);
			sort(f+1,f+c+1);
			for(int i=1;i<=s2-(n/2);i++)ans2-=f[i];
		}
	}else ans2=0;
	
	if(s3>=n/2){
		if(s3>n/2){
			int c=0;
			for(int i=1;i<=n;i++)
				if(a3[i]>=a1[i]&&a3[i]>=a2[i])
					f[++c]=a3[i]-max(a2[i],a1[i]);
			sort(f+1,f+c+1);
			for(int i=1;i<=s3-(n/2);i++)ans3-=f[i];
		}
	}else ans3=0;
	
	cout<<max(ans1,max(ans2,ans3))<<"\n";
	return;
}
signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	
	while(T--)
		solve();
	return 0;
}
