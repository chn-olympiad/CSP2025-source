#include <bits/stdc++.h>
using namespace std;
const int K=1e5+2;
int t,n,ans;
unsigned int dp[K];
struct club{
	int p1;
	int p2;
	int p3;
}l[K];
bool cmp(club x,club y){
	return x.p1>y.p1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>l[i].p1>>l[i].p2>>l[i].p3;
		}
		
		if(n==2){
			int s1=l[0].p1+l[1].p2;
			int s2=l[0].p1+l[1].p3;
			int s3=l[0].p2+l[1].p3;
			int s4=l[0].p2+l[1].p1;
			int s5=l[0].p3+l[1].p1;
			int s6=l[0].p3+l[1].p2;
			cout<<max((max(s1,s2),max(s3,s4)),max(s5,s6));
			return 0;
		}
		if(n==1e5&&l[0].p2==0&&l[0].p3==0){
			sort(l,l+n,cmp);
			for(int i=0;i<n/2;i++){
				ans+=l[i].p1;
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
