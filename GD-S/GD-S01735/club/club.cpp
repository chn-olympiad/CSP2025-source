#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int a1[n+1],a2[n+1],a3[n+1],b1=0,b2=0,b3=0,ans=0,c[n+1][3],g[n+1]={0},d[n+1][3],e[n+1],r=1;
		for(int j=1;j<=n;j++){
			int x=0;
			cin>>a1[j]>>a2[j]>>a3[j];
			if(a1[j]==0) x++;
			if(a2[j]==0) x++;
			if(a3[j]==0) x++;
			if(x==2){
				g[j]=1;
				d[r][1]=j;
				d[r][2]=max(max(a1[j],a2[j]),max(a2[j],a3[j]));
				r++;
			}
			if(x==3) e[j]=1;
			c[j][1]=j;
			c[j][2]=max(max(a1[j],a2[j]),max(a2[j],a3[j]));
		}
		for(int j=1;j<r-1;j++){
			for(int f=1;f<r-1;f++){
				if(d[f][2]<d[f+1][2]){
					int t;
					t=d[f][2];
					d[f][2]=d[f+1][2];
					d[f+1][2]=t;
					t=d[f][1];
					d[f][1]=d[f+1][1];
					d[f+1][1]=t;
				}
			}
		}
		for(int j=1;j<r;j++){
				if(d[j][2]==a1[d[j][1]]){
					if(b1<n/2){
						b1++;
						ans+=d[j][2];
						c[d[j][1]][1]=0;
					}else if(b2>=b3) b2++;
					else b3++;
				}
				else if(d[j][2]==a2[d[j][1]]){
						if(b2<n/2){
							b2++;
							ans+=d[j][2];
							c[d[j][1]][1]=0;
						}else if(b1>=b3) b1++;
						else b3++;
				}
				else if(d[j][2]==a3[d[j][1]]){
						if(b3<n/2){
							b3++;
							ans+=d[j][2];
							c[d[j][1]][1]=0;
						}else if(b1>=b2) b1++;
						else b2++;
				}
		}
		for(int j=1;j<=n;j++){
			if(e[j]==1){
				c[j][1]=-1;
			}
		}
		for(int j=1;j<n;j++){
			for(int f=1;f<n;f++){
				if(c[f][2]<c[f+1][2]){
					int t=0;
					t=c[f][2];
					c[f][2]=c[f+1][2];
					c[f+1][2]=t;
					t=c[f][1];
					c[f][1]=c[f+1][1];
					c[f+1][1]=t;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(c[j][1]==0||c[j][1]==-1) continue;
			if(c[j][2]==a1[c[j][1]]){
				if(b1<n/2){
					b1++;
					ans+=c[j][2];
					continue;
				}else if(a2[c[j][1]]>=a3[c[j][1]]){
					if(b2<n/2){
						b2++;
						ans+=a2[c[j][1]];
						continue;
					}else{
						b3++;
						ans+=a3[c[j][1]];
						continue;
					}
				}
			}
			if(c[j][2]==a2[c[j][1]]){
				if(b2<n/2){
					b2++;
					ans+=c[j][2];
					continue;
				}else if(a1[c[j][1]]>=a3[c[j][1]]){
					if(b1<n/2){
						b1++;
						ans+=a1[c[j][1]];
						continue;
					}else{
						b3++;
						ans+=a3[c[j][1]];
						continue;
					}
				}
			}
			if(c[j][2]==a3[c[j][1]]){
				if(b3<n/2){
					b3++;
					ans+=c[j][2];
					continue;
				}else if(a1[c[j][1]]>=a2[c[j][1]]){
					if(b1<n/2){
						b1++;
						ans+=a1[c[j][1]];
						continue;
					}else{
						b2++;
						ans+=a2[c[j][1]];
						continue;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(c[j][1]==-1){
				if(b1<n/2) b1++;
				else if(b2<n/2) b2++;
				else b3++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
