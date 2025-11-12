#include <bits/stdc++.h>
using namespace std;
int a[100000][3];//ÂúÒâ¶È
double qu[100000][3];//È¨
double maq[100000];
int hot[3];
int t;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	memset(qu,sizeof(qu),0);
	cin>>t;
	for(int i=1; i<=t; i++) {
		if(i>1) break;
		int n;
		int ans=0;
		int aj=0,bj=0,cj=0;
		cin>>n;
		for(int j=1; j<=n; j++) {
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		for(int j=1; j<=3; j++) {
			for(int m=1; m<=n; m++) hot[j]+=a[m][j];

		}
		for(int j=1; j<=n; j++) {

			if(hot[1]!=0)	qu[j][1]=a[j][1]*1.0/hot[1]*1.0;
			if(hot[2]!=0)	qu[j][2]=a[j][2]*1.0/hot[2]*1.0;
			if(hot[3]!=0)	qu[j][3]=a[j][3]*1.0/hot[3]*1.0;
		}
		for(int j=1; j<=n; j++) {
			if(qu[j][1]>qu[j][2]&&qu[j][1]>qu[j][3]&&aj<n/2) {
				maq[j]=a[j][1];
				aj++;
			}
			if(qu[j][2]>qu[j][1]&&qu[j][2]>qu[j][3]&&bj<n/2) {
				maq[j]=a[j][2];
				bj++;
			}
			if(qu[j][3]>qu[j][2]&&qu[j][3]>qu[j][1]&&cj<n/2) {

				maq[j]=a[j][3];
				cj++;
			}
			if(qu[j][3]==qu[j][2]&&qu[j][3]==qu[j][1]) {

				if(hot[1]<hot[2]&&hot[1]<hot[3]&&aj<n/2) {
					maq[j]=a[j][1];
					aj++;
				}

				if(hot[2]<hot[1]&&hot[2]<hot[3]&&bj<n/2) {
					maq[j]=a[j][2];
					bj++;
				}

				if(hot[3]<hot[2]&&hot[3]<hot[1]&&cj<n/2) {
					maq[j]=a[j][3];
					cj++;
				}

				if(hot[1]==hot[2]==hot[3]&&aj<n/2) {
					maq[j]=a[j][1];
					aj++;
				} else if(hot[1]==hot[2]==hot[3]&&bj<n/2) {
					maq[j]=a[j][2];
					bj++;
				} else if(hot[1]==hot[2]==hot[3]&&cj<n/2) {
					maq[j]=a[j][3];
					cj++;
				}
			}

		}
		for(int j=1; j<=n; j++) {
			ans+=maq[j];
		//	cout<<maq[j];
		}
		cout<<ans;
	}
	return 0;
}
