#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int b[100005][5];
bool b1[100005];
bool b2[100005];
int c[5],s[5],g[5],f[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--) {
		bool books=false;
		for(int i=1;i<=3;i++) {
			c[i]=0;
			s[i]=0;
			g[i]=0;
		}
		for(int i=1;i<=n;i++) {
			b1[i]=false;
			b2[i]=false;
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) {
				scanf("%d",&a[i][j]);
				if(a[i][j]==0) {
					b1[i]=true;
					books=true;
				}
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=2;j<=3;j++) {
				if(j==2) {
					if(a[i][j]>a[i][1]) {
						b[i][j]=1;
						b[i][1]=2;
					}
					else {
						b[i][1]=1;
						b[i][j]=2;
					}
				}
				else {
					if(b[i][1]==1) {
						if(a[i][j]>a[i][1]) {
							b[i][j]=1;
							b[i][1]=2;
							b[i][2]=3;
						}
						else {
							if(a[i][j]>a[i][2]) {
								b[i][j]=2;
								b[i][2]=3;
							}
							else {
								b[i][j]=3;
							}
						}
					}
					else {
						if(a[i][j]>a[i][2]) {
							b[i][j]=1;
							b[i][2]=2;
							b[i][1]=3;
						}
						else {
							if(a[i][j]>a[i][1]) {
								b[i][j]=2;
								b[i][1]=3;
							}
							else {
								b[i][j]=3;
							}
						}
					}
				}
			}
		}
		if(books) {
			for(int i=1;i<=n;i++) {
				int k=1,ans=0;
				if(b1[i]) {
					for(int j=1;j<=3;j++) {
						if(b2[i]==false) {
							if(b[i][j]==k) {
								if(c[j]<n/2) {
									c[j]++;
									s[j]+=a[i][j];
									b2[i]=true;
									if(g[j]==0) g[j]=i;
									else {
										if(a[i][j]<a[g[j]][j]) g[j]=i;
										else if(a[i][j]==a[g[j]][j]) {
											ans++;
											f[ans]=j;
										}
									}
									break;
								}
								else {
									if(a[i][j]>a[g[j]][j]) {
										s[j]=s[j]-a[g[j]][j]+a[i][j];
										b2[g[j]]=false;
										b2[i]=true;
										if(ans==0) g[j]=i;
										else {
											g[j]=f[ans];
											ans--;
										
										}
									}
								}
							}
							else continue;
						}
						else break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++) {
			int k=1,ans=0;
			for(int j=1;j<=3;j++) {
				if(b2[i]==false) {
					if(b2[i]==false) {
							if(b[i][j]==k) {
								if(c[j]<n/2) {
									c[j]++;
									s[j]+=a[i][j];
									b2[i]=true;
									if(g[j]==0) g[j]=i;
									else {
										if(a[i][j]<a[g[j]][j]) g[j]=i;
										else if(a[i][j]==a[g[j]][j]) {
											ans++;
											f[ans]=j;
										}
									}
									break;
								}
								else {
									if(a[i][j]>a[g[j]][j]) {
										s[j]=s[j]-a[g[j]][j]+a[i][j];
										b2[g[j]]=false;
										b2[i]=true;
										if(ans==0) g[j]=i;
										else {
											g[j]=f[ans];
											ans--;
										
										}
									}
								}
							}
							else continue;
						}
						else break;
				}
			}
		}
		printf("%d\n",s[1]+s[2]+s[3]);
	}
	return 0;
}