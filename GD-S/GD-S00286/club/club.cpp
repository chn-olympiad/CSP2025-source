#include<bits/stdc++.h>
using namespace std;
int b[200010],c[200010],d[200010];
int main(){
	int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=100010;i++)
			b[i]=0,c[i]=0,d[i]=0;
		int n,m;
		cin>>n;
		for(int i=1;i<=n;i++){
			int s[5],o=0;
			cin>>s[1]>>s[2]>>s[3];
			o=max(s[1],max(s[2],s[3]));
			for(int j=1;j<=3;j++)
				if(s[j]==o)
					d[i]=j;
			sort(s+1,s+4);
			b[i]=s[3];
			c[i]=s[3]-s[2];
		}
		int p[5];
		p[1]=0,p[2]=0,p[3]=0;
		for(int i=1;i<=n;i++)
			p[d[i]]++;
		int z=max(p[1],max(p[2],p[3]));
		for(int i=1;i<=3;i++)
			if(z==p[i])
				z=i;
		sort(p+1,p+4);
		if(p[3]<=n/2){
			long long ans=0ll;
			for(int i=1;i<=n;i++)
				ans+=b[i];
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			if(d[i]!=z)
				c[i]=1e9;
		sort(c+1,c+n+1);
		long long ans=0ll;
		for(int i=1;i<=n;i++)
			ans+=b[i];
		for(int i=1;i<=p[3]-(n/2);i++)
			ans-=c[i];
		cout<<ans<<"\n";
		continue;
	}
	return 0;
}
