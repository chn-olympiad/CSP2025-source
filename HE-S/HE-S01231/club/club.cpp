#include<bits/stdc++.h>
using namespace std;
struct club {
	long long cl,num;
}a[3];
long long dp[10000][10000],clu[3];
long long yi,er,sa;
long long sum;
bool cmp(club a,club b) {
	return a.num>b.num;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>n;
		for(int i=0; i<n; i++) {
			for(int j=0; j<3; j++) {
				cin>>dp[i][j];
			}
		}
		for(int i=n-1; i>=0; i--) {
			a[0].num=dp[i][0];
			a[0].cl=0;
			a[1].num=dp[i][1];
			a[1].cl=1;
			a[2].num=dp[i][2];
			a[2].cl=2;
			sort(a,a+3,cmp);
			if(clu[a[0].cl]<n/2){
				sum+=a[0].num;
				clu[a[0].cl]++;
			}else if(clu[a[1].cl]<n/2){
				sum+=a[1].num;
				clu[a[1].cl]++;
			}else if(clu[a[2].cl]<n/2){
				sum+=a[2].num;
				clu[a[2].cl]++;
			}
		}
		cout<<sum<<endl;
		for(int i=0; i<n; i++) {
			for(int j=0; j<3; j++) {
				dp[i][j]=0;
			}
		}
		sum=0;
		n=0;
		clu[0]=0;
		clu[1]=0;
		clu[2]=0;
		
	}
	return 0;
}
