#include <bits/stdc++.h>
using namespace std;
struct node1{
	int j1,j2,j3,maxmid;
};
struct node2{
	int m,let1,let2,let3;
};
node2 dp[100005][3];
int t;
int n;
node1 a[100005];
int nums;
bool cmp1(node1 x,node1 y){
	return x.j1>y.j1;
}
bool cmp2(node1 x,node1 y){
	return x.maxmid>y.maxmid;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		nums=0;
		cin >> n;
		bool l,r,p;
		l=r=p=true;
		for(int i=1;i<=n;i++){
			cin >> a[i].j1 >> a[i].j2 >> a[i].j3;
			a[i].maxmid=max(a[i].j1,max(a[i].j2,a[i].j3));
			if(a[i].j1!=0){
				p=0;
			}
			if(a[i].j2!=0){
				l=0;
			}
			if(a[i].j3!=0){
				r=0;
			}
		}
		if(l && r){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				nums+=a[i].j1;
			}
			cout << nums << endl;
		}
		else if(p){
			int let1,let2;
			let1=let2=n/2;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(let1>0 && a[i].maxmid==a[i].j2){
					nums+=a[i].j2;
					let1--;
				}
				else if(let2>0 && a[i].maxmid==a[i].j3){
					nums+=a[i].j3;
					let2--;
				}
			}
			cout << nums << endl;
		}
		else if(l){
			int let1,let2;
			let1=let2=n/2;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(let1>0 && a[i].maxmid==a[i].j1){
					nums+=a[i].j1;
					let1--;
				}
				else if(let2>0 && a[i].maxmid==a[i].j3){
					nums+=a[i].j3;
					let2--;
				}
			}
			cout << nums << endl;
		}
		else if(r){
			int let1,let2;
			let1=let2=n/2;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(let1>0 && a[i].maxmid==a[i].j1){
					nums+=a[i].j1;
					let1--;
				}
				else if(let2>0 && a[i].maxmid==a[i].j2){
					nums+=a[i].j2;
					let2--;
				}
			}
			cout << nums << endl;
		}
		else{
			memset(dp,0,sizeof(dp));
			dp[1][0].m=a[1].j1;
			dp[1][1].m=a[1].j2;
			dp[1][2].m=a[1].j3;
			dp[1][0].let1=dp[1][1].let2=dp[1][2].let3=n/2-1;
			dp[1][0].let2=dp[1][0].let3=dp[1][1].let1=dp[1][1].let3=dp[1][2].let1=dp[1][2].let2=n/2;
			for(int i=2;i<=n;i++){
				if(dp[i-1][0].let1>0 && dp[i-1][0].m+a[i].j1>dp[i][0].m){
					dp[i][0].m=dp[i-1][0].m+a[i].j1;
					dp[i][0].let2=dp[i-1][0].let2;
					dp[i][0].let3=dp[i-1][0].let3;
					dp[i][0].let1=dp[i-1][0].let1-1;
				}
				if(dp[i-1][0].let2>0 && dp[i-1][0].m+a[i].j2>dp[i][1].m){
					dp[i][1].m=dp[i-1][0].m+a[i].j2;
					dp[i][1].let2=dp[i-1][0].let2-1;
					dp[i][1].let3=dp[i-1][0].let3;
					dp[i][1].let1=dp[i-1][0].let1;
				}
				if(dp[i-1][0].let3>0 && dp[i-1][0].m+a[i].j3>dp[i][2].m){
					dp[i][2].m=dp[i-1][0].m+a[i].j3;
					dp[i][2].let2=dp[i-1][0].let2;
					dp[i][2].let3=dp[i-1][0].let3-1;
					dp[i][2].let1=dp[i-1][0].let1;
				}
				if(dp[i-1][1].let1>0 && dp[i-1][1].m+a[i].j1>dp[i][0].m){
					dp[i][0].m=dp[i-1][1].m+a[i].j1;
					dp[i][0].let2=dp[i-1][1].let2;
					dp[i][0].let3=dp[i-1][1].let3;
					dp[i][0].let1=dp[i-1][1].let1-1;
				}
				if(dp[i-1][1].let2>0 && dp[i-1][1].m+a[i].j2>dp[i][1].m){
					dp[i][1].m=dp[i-1][1].m+a[i].j2;
					dp[i][1].let2=dp[i-1][1].let2-1;
					dp[i][1].let3=dp[i-1][1].let3;
					dp[i][1].let1=dp[i-1][1].let1;
				}
				if(dp[i-1][1].let1>0 && dp[i-1][1].m+a[i].j3>dp[i][2].m){
					dp[i][2].m=dp[i-1][1].m+a[i].j3;
					dp[i][2].let2=dp[i-1][1].let2;
					dp[i][2].let3=dp[i-1][1].let3-1;
					dp[i][2].let1=dp[i-1][1].let1;
				}
				if(dp[i-1][2].let1>0 && dp[i-1][2].m+a[i].j1>dp[i][0].m){
					dp[i][0].m=dp[i-1][2].m+a[i].j1;
					dp[i][0].let2=dp[i-1][2].let2;
					dp[i][0].let3=dp[i-1][2].let3;
					dp[i][0].let1=dp[i-1][2].let1-1;
				}
				if(dp[i-1][2].let2>0 && dp[i-1][2].m+a[i].j2>dp[i][1].m){
					dp[i][1].m=dp[i-1][2].m+a[i].j2;
					dp[i][1].let2=dp[i-1][2].let2-1;
					dp[i][1].let3=dp[i-1][2].let3;
					dp[i][1].let1=dp[i-1][2].let1;
				}
				if(dp[i-1][2].let3>0 && dp[i-1][2].m+a[i].j3>dp[i][2].m){
					dp[i][2].m=dp[i-1][2].m+a[i].j3;
					dp[i][2].let2=dp[i-1][2].let2;
					dp[i][2].let3=dp[i-1][2].let3-1;
					dp[i][2].let1=dp[i-1][2].let1;
				}
			}
			cout << max(dp[n][0].m,max(dp[n][1].m,dp[n][2].m)) << endl;
		}
	}
	return 0;
}
