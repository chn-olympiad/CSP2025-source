#include<bits/stdc++.h>
using namespace std;
int s[100005][3],c[100005],well[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		int n,ans=0,sov;
		cin>>n;
		memset(s,0,sizeof(s));
		memset(c,0,sizeof(c));
		memset(well,0,sizeof(well));
		for(int i=1;i<=n;++i){
		 	cin>>s[i][0]>>s[i][1]>>s[i][2];
		 	if(s[i][0]>=s[i][1] and s[i][0]>=s[i][2]) well[0]++;
		 	else if(s[i][0]<=s[i][1] and s[i][1]>=s[i][2]) well[1]++;
		 	else well[2]++;
		}
		if(well[0]>=well[1] and well[0]>=well[2]) sov=0;
		else if(well[0]<=well[1] and well[1]>=well[2]) sov=1;
		else sov=2;
		if(sov==0){
			for(int i=1;i<=n;++i)
				c[i]=max(s[i][1]-s[i][0],s[i][2]-s[i][0]);
			sort(c+1,c+n+1);
			for(int i=n;;i--){
				if(c[i]>0 or i*2>n)
					ans+=c[i];
				else break;
			}
			for(int i=1;i<=n;++i) ans+=s[i][0];
			cout<<ans<<endl;
		}
		else if(sov==1){
			for(int i=1;i<=n;++i)
				c[i]=max(s[i][0]-s[i][1],s[i][2]-s[i][1]);
			sort(c+1,c+n+1);
			for(int i=n;;i--){
				if(c[i]>0 or i*2>n)
					ans+=c[i];
				else break;
			}
			for(int i=1;i<=n;++i) ans+=s[i][1];
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;++i)
				c[i]=max(s[i][0]-s[i][2],s[i][1]-s[i][2]);
			sort(c+1,c+n+1);
			for(int i=n;;i--){
				if(c[i]>0 or i*2>n)
					ans+=c[i];
				else break;
			}
			for(int i=1;i<=n;++i) ans+=s[i][2];
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
