#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001][4],y,e,s,yi[1000001],er[1000001],san[1000001],sum;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int g=1; g<=t; g++) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])a[i][0]=1;
			if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3])a[i][0]=2;
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1])a[i][0]=3;
			if(a[i][0]==1&&y>=n/2) {
				int ma=0,f,k;
				for(int j=1; j<=y; j++) {
					if(a[yi[j]][2]+a[i][1]-a[yi[j]][1]>ma) {
						ma=a[yi[j]][2]+a[i][1]-a[yi[j]][1];
						f=2;
						k=j;
					}
					if(a[yi[j]][3]+a[i][1]-a[yi[j]][1]>ma) {
						ma=a[yi[j]][3]+a[i][1]-a[yi[j]][1];
						f=3;
						k=j;
					}
				}
				if(ma<=max(a[i][2],a[i][3])) {
					if(a[i][2]>=a[i][3]) {
						er[++e]=i;
					} else {
						san[++s]=i;
					}
				} else {
					if(f==2) {
						er[++e]=yi[k];
						yi[k]=i;
					}
					if(f==3) {
						san[++s]=yi[k];
						yi[k]=i;
					}
				}
			} else if(a[i][0]==2&&e>=n/2) {
				int ma=0,f,k;
				for(int j=1; j<=e; j++) {
					if(a[er[j]][1]+a[i][2]-a[er[j]][2]>ma) {
						ma=a[er[j]][1]+a[i][2]-a[er[j]][2];
						f=1;
						k=j;
					}
					if(a[er[j]][3]+a[i][2]-a[er[j]][2]>ma) {
						ma=a[er[j]][3]+a[i][2]-a[er[j]][2];
						f=3;
						k=j;
					}
				}
				if(ma<=max(a[i][1],a[i][3])) {
					if(a[i][1]>=a[i][3]) {
						yi[++y]=i;
					} else {
						san[++s]=i;
					}
				} else {
					if(f==1) {
						yi[++y]=er[k];
						er[k]=i;
					}
					if(f==3) {
						san[++s]=er[k];
						er[k]=i;
					}
				}
			} else if(a[i][0]==3&&s>=n/2) {
				int ma=0,f,k;
				for(int j=1; j<=s; j++) {
					if(a[san[j]][1]+a[i][3]-a[san[j]][3]>ma) {
						ma=a[san[j]][1]+a[i][3]-a[san[j]][3];
						f=1;
						k=j;
					}
					if(a[san[j]][2]+a[i][3]-a[san[j]][3]>ma) {
						ma=a[san[j]][2]+a[i][3]-a[san[j]][3];
						f=2;
						k=j;
					}
				}
				if(ma<=max(a[i][1],a[i][2])) {
					if(a[i][1]>=a[i][2]) {
						yi[++y]=i;
					} else {
						er[++e]=i;
					}
				} else {
					if(f==1) {
						yi[++y]=san[k];
						san[k]=i;
					}
					if(f==2) {
						er[++e]=san[k];
						san[k]=i;
					}
				}
			} else {
				if(a[i][0]==1) {
					yi[++y]=i;
				}
				if(a[i][0]==2) {
					er[++e]=i;
				}
				if(a[i][0]==3) {
					san[++s]=i;
				}
			}
		}
		for(int i=1; i<=y; i++) {
			sum+=a[yi[i]][1];
		}
		for(int i=1; i<=e; i++) {
			sum+=a[er[i]][2];
		}
		for(int i=1; i<=s; i++) {
			sum+=a[san[i]][3];
		}
		cout<<sum<<endl;
		y=0;
		e=0;
		s=0;
		sum=0;
		memset(a,0,sizeof a);
		memset(yi,0,sizeof yi);
		memset(er,0,sizeof er);
		memset(san,0,sizeof san);
	}

	return 0;
}

