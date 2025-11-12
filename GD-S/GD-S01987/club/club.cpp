#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15;
int t,n,a[3][N],c[3][N],s[3];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(c,0xff,sizeof c);
		cin>>n;
		int k=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
			if(a[0][i]>=a[1][i]&&a[0][i]>=a[2][i]){
				c[0][i]=min(a[0][i]-a[1][i],a[0][i]-a[2][i]);
				s[0]++;
				ans+=a[0][i];
			}
			else if(a[1][i]>=a[0][i]&&a[1][i]>=a[2][i]){
				c[1][i]=min(a[1][i]-a[0][i],a[1][i]-a[2][i]);
				s[1]++;
				ans+=a[1][i];
			}
			else{
				c[2][i]=min(a[2][i]-a[0][i],a[2][i]-a[1][i]);
				s[2]++;
				ans+=a[2][i];
			}
		}
		if(s[0]>k){
			sort(c[0]+1,c[0]+n+1);
			for(int i=1;i<=s[0]-k;i++)ans-=c[0][i];
		}
		if(s[1]>k){
			sort(c[1]+1,c[1]+n+1);
			for(int i=1;i<=s[1]-k;i++)ans-=c[1][i];
		}
		if(s[2]>k){
			sort(c[2]+1,c[2]+n+1);
			for(int i=1;i<=s[2]-k;i++)ans-=c[2][i];
		}
		cout<<ans<<endl;
		s[0]=0,s[1]=0,s[2]=0;
		ans=0;
	}
	return 0;
} 
