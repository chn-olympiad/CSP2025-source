#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--) {
		int n,s=1,ans=0;
		vector<int> chose;
		cin>>n;
		if (n==2) {
			int a[4],b[4],maxn=INT_MIN;
			for (int i=1;i<=3;i++) cin>>a[i];
			for (int i=1;i<=3;i++) cin>>b[i];
			for (int i=1;i<=3;i++) {
				for (int j=1;j<=3;j++) {
					if(i==j) continue;
					if (a[i]+b[j]>maxn) maxn=a[i]+b[j];
				}
			}
			ans=maxn;
		}
		else if (n==4) {
			int a[4],b[4],c[4],d[4],maxn=INT_MIN;
			for (int i=1;i<=3;i++) cin>>a[i];
			for (int i=1;i<=3;i++) cin>>b[i];
			for (int i=1;i<=3;i++) cin>>c[i];
			for (int i=1;i<=3;i++) cin>>d[i];
			for (int i=1;i<=3;i++) {
				for (int j=1;j<=3;j++) {
					for (int k=1;k<=3;k++) {
						for (int l=1;l<=3;l++) {
							if ((i==j && i==k) || (i==j && i==l) || (j==k && j==l)) continue;
							int num=a[i]+b[j]+c[k]+d[l];
							if (num>maxn) maxn=num;
						}
					}
				}
			}
			ans=maxn;
		}
		cout<<ans<<endl;
	}
	return 0;
}
