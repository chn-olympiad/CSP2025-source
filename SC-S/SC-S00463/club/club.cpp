#include<bits/stdc++.h>
using namespace std;
int a[100005],b,c;
long long s;
//int dp[100][100][100];
//struct clb{
//	int a;
//	int b;
//	int c;
//};
//clb s[100005];
void ko(){
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>s[i].a>>s[i].b>>s[i].c;
//	}
//	int mid=n/2;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=mid;j++){
//			for(int k=1;k<=mid;k++){
//			    if(i+j+k>n){
//			    	break;
//				}	
//				if(k>mid){
//			    	continue;
//			    }
//		    	int maxx=max(dp[i-1][j][k]+s[i].a,dp[i][j-1][k]+s[i].b);
//		    	dp[i][j][k]=max(maxx,dp[i][j][k-1]+s[i].c);
//			}			
//		}
//	}
//	int maxn=-1048576;
//	for(int i=1;i<=n;i++){
//		for(int j=mid-i;j<=mid;j++){
//			int k=n-i-j;
//			maxn=max(maxn,dp[i][j][k]);
//		}
//	}
//	cout<<maxn<<endl;
//	memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b>>c;
	}
	sort(a+1,a+n+1);
	int mid=n/2;
	for(int i=n;i>mid;i--){
		s+=a[i];
	}
	cout<<s<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
	cin>>t;
	while(t--){
		ko();
	}
	return 0;
}