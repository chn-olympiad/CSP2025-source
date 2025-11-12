#include<bits/stdc++.h>
using namespace std;
int n,a[200010][5],t,n1,b[200010][3],c[200010],d[200010],qu[5][100010],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(d,0,sizeof d);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		cin>>n;
		n1=n/2;
		for(int i=1;i<=n;i++){
			int m1,m2;
			cin>>a[i][1];
			b[i][1]=1;
			m1=1;
			cin>>a[i][2];
			if(a[i][2]>a[i][1]){
				b[i][2]=1;
				b[i][1]=2;
				m1=2;
				m2=1;
			}
			else{
				b[i][2]=2;
				m2=2;
			}
			cin>>a[i][3];
			if(a[i][3]>a[i][m1]){
				b[i][3]=1;
				b[i][m1]=2;
				b[i][m2]=3;
			}
			else if(a[i][3]>a[i][m2]){
				b[i][3]=2;
				b[i][m2]=3;
			}
			else b[i][3]=3;
		}
		for(int j=1;j<=n1;j++){
			b[0][1]=4;
			c[j]=0;
			for(int i=1;i<=n;i++){
				if(b[c[j]][1]>b[i][1] && d[i]==0 && b[i][1]<b[i][2] && b[i][1]<b[i][3]){
					c[j]=i;
				}
				else if(b[c[j]][1]==b[i][1] && d[i]==0 && b[i][1]<b[i][2] && b[i][1]<b[i][3]){
					if(b[c[j]][2]==b[i][2]){
						if(a[c[j]][1]==a[i][1]){
							if(a[c[j]][2]==a[i][2]){
								if(a[c[j]][3]>a[i][3]){
									c[j]=i;
								}
							}
							else if(a[c[j]][2]<a[i][2]){
								c[j]=i;
							}
						}
						else if(a[c[j]][1]<a[i][1]){
							c[j]=i;
						}
					}
					else if(b[c[j]][2]<b[i][2]){
						c[j]=i;
					}
				}
			}
			qu[1][j]=c[j];
			d[c[j]]=1;
		}
		for(int j=1;j<=n1;j++){
			b[0][2]=4;
			c[j]=0;
			for(int i=1;i<=n;i++){
				if(b[c[j]][2]>b[i][2] && d[i]==0 && b[i][2]<b[i][3]){
					c[j]=i;
				}
				else if(b[c[j]][2]==b[i][2] && d[i]==0 && b[i][2]<b[i][3]){
					if(b[c[j]][3]==b[i][3]){
						if(a[c[j]][2]==a[i][2]){
							if(a[c[j]][3]>a[i][3]){
								c[j]=i;
							}
						}
						else if(a[c[j]][2]<a[i][2]){
							c[j]=i;
						}
					}
					else if(b[c[j]][3]<b[i][3]){
						c[j]=i;
					}
				}
			}
			qu[2][j]=c[j];
			d[c[j]]=1;
		}
		for(int j=1;j<=n1;j++){
			b[0][3]=4;
			c[j]=0;
			for(int i=1;i<=n;i++){
				if(b[c[j]][3]>b[i][3] && d[i]==0){
					c[j]=i;
				}
				else if(b[c[j]][3]==b[i][3] && d[i]==0){
					if(a[c[j]][3]<a[i][3]){
						c[j]=i;
					}
				} 
			}
			qu[3][j]=c[j];
			d[c[j]]=1;
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n1;j++){
				ans+=a[qu[i][j]][i];
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
