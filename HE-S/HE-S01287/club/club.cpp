#include<bits/stdc++.h>
using namespace std;
int t,n;
struct d{
	int m;int p;int q;
}a[100001];
int b[100001];
struct node{
	int x;int y;int z;
}dp[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].m>>a[j].p>>a[j].q;
			b[1]=a[j].m;
			b[2]=a[j].p;
			b[3]=a[j].q;
			sort(b+1,b+4);
			dp[j].x=b[3]-b[2];
			dp[j].y=b[2]-b[1];
			dp[j].z=j;
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(dp[j].x<dp[k].x){
					swap(dp[j],dp[k]);
					swap(a[j],a[k]);
				}
				else if(dp[j].x==dp[k].x&&dp[j].y<dp[k].y){
					swap(dp[j],dp[k]);
					swap(a[j],a[k]);
				}
			}
		}
		int tm=n/2+1,tp=n/2+1,tq=n/2+1;
			for(int j=1;j<=n;j++){
				b[1]=a[j].m;
				b[2]=a[j].p;
				b[3]=a[j].q;
				sort(b+1,b+4);
				if(b[3]==a[j].m&&tm>1){
					ans+=a[j].m;
					tm--;
				}
				else if(b[3]==a[j].p&&tp>1){
					ans+=a[j].p;
					tp--;
				}
				else if(b[3]==a[j].q&&tq>1){
					ans+=a[j].q;
					tq--;
				}
				else if(b[3]==a[j].q&&tq==1&&b[2]==a[j].m&&tm>1){
					ans+=a[j].m;
					tm--;
				}
				else if(b[3]==a[j].q&&tq==1&&b[2]==a[j].p&&tp>1){
					ans+=a[j].p;
					tp--;
				}
				else if(b[3]==a[j].m&&tm==1&&b[2]==a[j].p&&tp>1){
					ans+=a[j].p;
					tp--;
				}
				else if(b[3]==a[j].m&&tm==1&&b[2]==a[j].q&&tq>1){
					ans+=a[j].q;
					tq--;
				}
				else if(b[3]==a[j].p&&tp==1&&b[2]==a[j].m&&tm>1){
					ans+=a[j].m;
					tm--;
				}
				else if(b[3]==a[j].p&&tp==1&&b[2]==a[j].q&&tq>1){
					ans+=a[j].q;
					tq--;
				}
				else if(b[3]==a[j].m&&tm==1&&b[2]==a[j].p&&tp==1){
					ans+=a[j].q;
					tq--;
				}
				else if(b[3]==a[j].m&&tm==1&&b[2]==a[j].q&&tq==1){
					ans+=a[j].p;
					tp--;
				}
				else if(b[3]==a[j].p&&tp==1&&b[2]==a[j].m&&tm==1){
					ans+=a[j].q;
					tq--;
				}
				else if(b[3]==a[j].p&&tp==1&&b[2]==a[j].q&&tq==1){
					ans+=a[j].m;
					tm--;
				}
				else if(b[3]==a[j].q&&tq==1&&b[2]==a[j].p&&tp==1){
					ans+=a[j].m;
					tm--;
				}
				else if(b[3]==a[j].q&&tq==1&&b[2]==a[j].m&&tm==1){
					ans+=a[j].p;
					tp--;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}

