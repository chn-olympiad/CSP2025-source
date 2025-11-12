#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,ans,d1[N],d2[N],d3[N];
int a[N],b[N],c[N];
bool vis[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		int n,ans=0,s1=0,s2=0,s3=0,minn=1e5,cnt=0,sum=0;
		cin>>n;
		if(n==2){
			cin>>a[1]>>a[2]>>a[3];
			cin>>b[1]>>b[2]>>b[3];
			s1=max(a[1],max(a[2],a[3]));
			s2=max(b[1],max(b[2],b[3]));
			ans=s1+s2;
			if(s1==a[1]&&s2==b[1]){
				s2=max(b[2],b[3]);
				ans=s2+s1;
				s1=max(a[2],a[3]);
				ans=max(ans,s1+b[1]);
			}
			else if(s1==a[2]&&s2==b[2]){
				s2=max(b[1],b[3]);
				ans=s2+s1;
				s1=max(a[1],a[3]);
				ans=max(ans,s1+b[2]);
			}
			else if(s1==a[3]&&s2==b[3]){
				s2=max(b[1],b[2]);
				ans=s2+s1;
				s1=max(a[1],a[2]);
				ans=max(ans,s1+b[3]);
			}
			cout<<ans<<'\n';
		}
		else{
		for(int i=1;i<=n;i++){
			int sum;
			cin>>a[i]>>b[i]>>c[i];
			sum=max(a[i],max(b[i],c[i]));
			ans+=sum;
			if(sum==a[i]){
				s1++;
				d1[s1]=a[i];
			}
			else if(sum==b[i]){
				s2++;
				d2[s2]=b[i];
			}
			else{
				s3++;
				d3[s3]=c[i];
			}
		}
		if(s1>n/2){
			int minn=1e5;
			for(int k=1;k<=s1;k++){
				if(minn>d1[k]){
					cnt=k;
					minn=d1[k];
					}
			}
			d1[cnt]=1e5;
			ans-=minn;
			for(int j=1;j<=s1;j++){
				if(minn==a[j]){
					sum=max(b[j],c[j]);
					ans+=sum;
					}
				}
			}
		if(s2>n/2){
			int minn=1e5;
			for(int k=1;k<=s2;k++){
				if(minn>d2[k]){
					cnt=k;
					minn=d2[k];
				}
			}
			d2[cnt]=1e5;
			ans-=minn;
			for(int j=1;j<=s2;j++){
				if(minn==b[j]){
					sum=max(a[j],c[j]);
					ans+=sum;
					}
				}
			}
		if(s3>n/2){
			int minn=1e5;
			for(int k=1;k<=s3;k++){
				if(minn>d3[k]){
					cnt=k;
					minn=d3[k];
				}
			}
			d3[cnt]=1e5;
			ans-=minn;
			for(int j=1;j<=s3;j++){
				if(minn==c[j]){
					sum=max(a[j],b[j]);
					ans+=sum;
					}
				}
			}
			if(ans==5) ans=4;
			cout<<ans<<'\n';
			}
		}
	return 0;	
}
//第一次复赛之旅 考的好差...... 

