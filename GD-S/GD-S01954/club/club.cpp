#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],p[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])p[i]=1;
			else if(a[i][2]>a[i][3])p[i]=2;
			else p[i]=3;
			ans+=a[i][p[i]];
			sort(a[i]+1,a[i]+4);
			c[i]=a[i][3]-a[i][2];
		}
		sort(c+1,c+n+1);
		int s[5]={0,0,0,0};
		for(int i=1;i<=n;i++)s[p[i]]++;
		int m=min(n/2-s[1],min(n/2-s[2],n/2-s[3]));
		if(m<0)for(int i=1;i<=-m;i++)ans-=c[i];
		cout<<ans<<endl;
	}
}
