#include <bits/stdc++.h>
using namespace std;
int t,n,c[3],s[100005][4],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		c[0]=0;
		c[1]=0;
		c[2]=0;
		ans=0;
		cin>>n;
		int m=n/2;
		for(int i=0;i<n;i++){
			cin>>s[i][0]>>s[i][1]>>s[i][2];
		}
		if(n==2){
			int p=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i!=j)
					p=max(p,s[0][i]+s[1][j]);
				}
			}
			cout<<p;
			return 0;
		}
		for(int i=0;i<n;i++){
			int zd=max(max(s[i][0],s[i][1]),s[i][2]);		
			if(c[0]<m&&c[1]<m&&c[2]<m){
				if(zd==s[i][0]){
					ans+=zd;
					c[0]++;
				}
				else if(zd==s[i][1]){
					ans+=zd;
					c[1]++;
				}
				else if(zd==s[i][2]){
					ans+=zd;
					c[2]++;
				}
			}
			else{
				if(c[0]>=m){
					int zd=max(s[i][1],s[i][2]);
					if(zd==s[i][1]){
						ans+=zd;
						c[1]++;
					}
					else if(zd==s[i][2]){
						ans+=zd;
						c[2]++;
					}
				}
				if(c[1]>=m){
					int zd=max(s[i][0],s[i][2]);
					if(zd==s[i][0]){
						ans+=zd;
						c[0]++;
					}
					else if(zd==s[i][2]){
						ans+=zd;
						c[2]++;
					}
				}
				if(c[2]>=m){
					int zd=max(s[i][0],s[i][1]);
					if(zd==s[i][0]){
						ans+=zd;
						c[0]++;
					}
					else if(zd==s[i][1]){
						ans+=zd;
						c[1]++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
