#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
long long ans;
int p[5][100005];
int q[100005];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--) {
		memset(a,0,sizeof(a));
		for(int i=0; i<3; i++)
			p[i][0]=0;
		ans=0;
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int maxk=0;
			for(int j=1; j<3; j++)
				if(a[i][j]>a[i][maxk]) {
					maxk=j;
				}
			p[maxk][++p[maxk][0]]=i;
			ans+=a[i][maxk];
		}
		int maxk=-1;
		for(int i=0; i<3; i++) {
			if(p[i][0]>n/2) {
				maxk=i;
			}
		}
		if(maxk==-1) {
			cout<<ans<<endl;
			continue;
		}
		for(int i=1; i<p[maxk][0]+1; i++) {
			int it=p[maxk][i];
			int t=20005;
			for(int j=0; j<3; j++) {
				int t1=a[it][maxk]-a[it][j];
				if(t>t1&&maxk!=j) {
					t=t1;
				}
			}
			q[i-1]=t;
		}
		sort(q,q+p[maxk][0],cmp);
		for(int i=n/2; i<p[maxk][0]; i++)
			ans-=q[i];
		cout<<ans<<endl;
	}
	return 0;
}
