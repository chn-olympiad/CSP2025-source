#include<bits/stdc++.h>
using namespace std;
int t;
const int maxn=1e5+10;
struct S{
	int club1,club2,club3;
	int op;
}a[maxn];
bool cmp1(S x,S y){
	return x.club1 >y.club1 ;
}
bool cmp2(S x,S y){
	if(max(x.club1,x.club2 )==max(y.club1 ,y.club2 ))return min(x.club1,x.club2 )>min(y.club1 ,y.club2 );
	return max(x.club1,x.club2 )>max(y.club1 ,y.club2 );
}
int dp[maxn][5][2];//选到第i个成员选第(1,2,3)部门一共最大满意度 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		bool flagA,flagB;
		cin>>n;
		int cnt1=n/2,cnt2=n/2,cnt3=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].club1 >>a[i].club2>>a[i].club3 ;
			if(a[i].club2 !=0||a[i].club3 !=0)flagA=1;
			if(a[i].club3 !=0)flagB=1;
		}
		if(!flagA){
			long long ans=0;
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].club1 ;
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(!flagB){
			long long ans=0;
			int cnt1=n/2;
			int cnt2=n/2;
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=max(a[i].club1 ,a[i].club2);
				if(max(a[i].club1 ,a[i].club2)==a[i].club1 )cnt1--;
				if(max(a[i].club1 ,a[i].club2)==a[i].club2 )cnt2--;
			}
			for(int i=n/2+1;i<=n;i++){
				if(max(a[i].club1 ,a[i].club2)==a[i].club1&&cnt1>0){
					ans+=a[i].club1 ;
					cnt1--;
					continue;
				}else{
					ans+=a[i].club2 ;
					cnt2--;
					continue;
				}
				if(max(a[i].club1 ,a[i].club2)==a[i].club2&&cnt2>0){
					ans+=a[i].club2 ;
					cnt2--;
				}else{
					ans+=a[i].club1 ;
					cnt1--;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			dp[i][1][1]=dp[i][2][1]=dp[i][3][1]=0;
			dp[i][1][0]=dp[i][2][0]=dp[i][3][0]=0;
		}
		for(int i=1;i<=n;i++){
			if(cnt1){
				dp[i][1][1]=max(dp[i][1][1],max(dp[i-1][1][1],max(dp[i-1][2][1],max(dp[i-1][3][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0]))))))+a[i].club1;
//				dp[i][1][1]=max(dp[i][1][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0])))+a[i].club1;
				cnt1--;	
			}
			else{
				dp[i][1][0]=max(dp[i][1][0],max(dp[i-1][1][1],max(dp[i-1][2][1],max(dp[i-1][3][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0]))))));
//				dp[i][1][0]=max(dp[i][1][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0])));
			}
			if(cnt2){
				dp[i][2][1]=max(dp[i][2][1],max(dp[i-1][1][1],max(dp[i-1][2][1],max(dp[i-1][3][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0]))))))+a[i].club2;
//				dp[i][2][1]=max(dp[i][2][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0])))+a[i].club2;
				cnt2--;
			}
			else{
				dp[i][2][0]=max(dp[i][2][1],max(dp[i-1][1][1],max(dp[i-1][2][1],max(dp[i-1][3][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0]))))));
//				dp[i][2][0]=max(dp[i][2][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0])));
			}
			if(cnt3){
				dp[i][3][1]=max(dp[i][3][1],max(dp[i-1][1][1],max(dp[i-1][2][1],max(dp[i-1][3][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0]))))))+a[i].club3;
//				dp[i][3][1]=max(dp[i][3][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0])))+a[i].club3;
				cnt3--;
			}
			else{
				dp[i][3][0]=max(dp[i][3][1],max(dp[i-1][1][1],max(dp[i-1][2][1],max(dp[i-1][3][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0]))))));
//				dp[i][3][0]=max(dp[i][3][1],max(dp[i-1][1][0],max(dp[i-1][2][0],dp[i-1][3][0])));
			}
		} 
//		cout<<"\n";
		cout<<max(dp[n][1][1],max(dp[n][2][1],max(dp[n][3][1],max(dp[n][3][0],max(dp[n][2][0],dp[n][1][0])))))<<"\n";
	}
	
	return 0;
} 
/*
3 

4

4 2 1

3 2 4

5 3 4

3 5 1

4

0 1 0

0 1 0

0 2 0

0 2 0

2

10 9 8

4 0 0


*/
