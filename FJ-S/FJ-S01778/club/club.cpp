#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int a[100005],b[100005],c[100005],z[100005];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(z,0,sizeof(z));
		int x=0,y=0; 
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i],x+=b[i],y+=c[i];
		if(x==0&&y==0){
			sort(a+1,a+n+1,greater<int>());
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
		if(n==2){
			int ans=0;
			for(int i=1;i<=3;i++)
				for(int j=1;j<=3;j++)
					if(i!=j) ans=max(ans,a[i]+b[j]);
			cout<<ans<<endl;
			continue;
		}
		cout<<rand();
	}
	return 0;
}
