#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	while(t--){
		int n,a[100010][3],ans=0,jx=0,jy=0,jz=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i][1]=read();a[i][2]=read();a[i][3]=read();
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) jx++;
			else if(a[i][2]>a[i][3]&&a[i][2]>a[i][1]) jy++;
			else jz++;
		}
//		cout<<jx<<" "<<jy<<" "<<jz<<"\n";
		if(jx<=n/2&&jy<=n/2&&jz<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		int dp[100010]={0};
		if(jx>n/2){
			ans=0;
			int A[100010];
			for(int i=1;i<=n;i++){
				ans+=a[i][1];
				A[i]=max(a[i][2],a[i][3])-a[i][1];
			}
			sort(A+1,A+n+1);
//			for(int i=1;i<=n;i++){
//				cout<<A[i]<<" ";
//			}
//			cout<<":A\n";
			for(int i=n/2+1;i<=n;i++){
//				cout<<A[i]<<" "<<ans+A[i]<<" \n";
				ans+=A[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(jy>n/2){
			ans=0;
			int A[100010];
			for(int i=1;i<=n;i++){
				ans+=a[i][2];
				A[i]=max(a[i][1],a[i][3])-a[i][2];
			}
			sort(A+1,A+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=A[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(jz>n/2){
			ans=0;
			int A[100010];
			for(int i=1;i<=n;i++){
				ans+=a[i][3];
				A[i]=max(a[i][1],a[i][2])-a[i][3];
			}
			sort(A+1,A+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=A[i];
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
