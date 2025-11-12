#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5,Ns = 3005;
struct node{
	int x,y,z;
}p[N];
bool cmp(node xx,node yy) {
	return max(xx.x,max(xx.y,xx.z)) > max(yy.x,max(yy.y,yy.z));
}
bool cmp2(node xx,node yy) {
	return xx.x>yy.x;
}
bool cmp3(node xx,node yy) {
	return xx.y > yy.y;
}
bool cmp4(node xx,node yy) {
	return xx.z>yy.z;
}
int res = 0,res1 = 0,res2 = 0,res3 = 0;
int n,c[4],d[N][4],dp[2][Ns][Ns];
int sf1[N],sf2[N],sf3[N];
void slv() {
	bool tg = 1,tg2 = 1;
	res = 0,res1 = 0,res2 = 0,res3 = 0;
	cin >> n ;
	c[1] = 0,c[2] = 0,c[3] = 0;
	for(int i=1;i<=n;i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
		tg = tg && (p[i].y==0&&p[i].z==0);
		tg2 = tg2 && (p[i].z==0);
	}
	sf1[n+1]=0,sf2[n+1]=0,sf3[n+1]=0;
	for(int i=n;i>=1;i--) {
		sf1[i] = sf1[i+1]+max(p[i].y,p[i].z);
		sf2[i] = sf2[i+1]+max(p[i].x,p[i].z);
		sf3[i] = sf3[i+1]+max(p[i].x,p[i].y);
	}
	if(n<=2000) {
		for(int i=0;i<=1;i++) {
			for(int j=0;j<=n;j++) {
				for(int k=0;k<=n;k++) dp[i][j][k] = 0;
			}
		}
		dp[0][0][0] = 0;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=n/2;j++) {
				for(int k=0;k<=n/2;k++) {
					if(i-j-k >= 0 && i-j-k<=n/2) {
						if(i-j-k>=1)dp[i&1][j][k] = max(dp[i&1][j][k],dp[(i-1)&1][j][k]+p[i].z);
						if(k>=1)dp[i&1][j][k] = max(dp[i&1][j][k],dp[(i-1)&1][j][k-1]+p[i].y);
						if(j>=1)dp[i&1][j][k] = max(dp[i&1][j][k],dp[(i-1)&1][j-1][k]+p[i].x); 
						if(i==n) res = max(res,dp[n&1][j][k]);
					}
				}
			}
		}
	}
	else if(tg) {
		sort(p+1,p+n+1,cmp);
		res = 0,res1 = 0;
		for(int i=1;i<=n;i++) {
			if(c[1]<n/2) res += p[i].x; 
		}
	}
	else if(tg2) {
		sort(p+1,p+n+1,cmp2);
		int pf = 0;
		res = 0,res1 = 0;
		for(int i=1;i<=n;i++) {
			pf += p[i].x;
			res = max(res,pf + sf1[i+1]);
		}
		sort(p+1,p+n+1,cmp3);
		pf = 0;
		for(int i=1;i<=n;i++) {
			pf += p[i].y;
			res = max(res,pf+sf2[i+1]);
		}
		// cout<<"enter\n";
	}
	else {
		res=0;
		for(int i=1;i<=n;i++) {
			int s = max(p[i].x,max(p[i].y,p[i].z));
			if(p[i].x==s&&c[1]<n/2) res += p[i].x,c[1]++;
			else if(p[i].y>p[i].z&&c[2]<n/2) res += p[i].y,c[2]++; 
			else res += p[i].z,c[3]++;
		}
		// res=0;
		res1 = 0,res2 = 0,res3 = 0;
		int pf1=0,pf2=0,pf3=0;
		sort(p+1,p+n+1,cmp2);
		for(int i=1;i<=n/2;i++) {
			pf1 += p[i].x;
			res = max(res,pf1+sf1[i+1]);
		}
		sort(p+1,p+n+1,cmp3);
		for(int i=1;i<=n/2;i++) {
			pf2 += p[i].y;
			res = max(res,pf2+sf2[i+1]);
		}
		sort(p+1,p+n+1,cmp4);
		for(int i=1;i<=n/2;i++) {
			pf3 += p[i].z;
			res = max(res,pf3+sf3[i+1]);
		}
		// for(int i=n/2;)
	}
	cout << res << "\n";
	// sort(p+1,p+n+1,cmp);
	// d[n+1][1][2] = 1;
	// d[n+1][1][3] = 1;
	// d[n+1][2][3] = 2;
	// for(int i=n;i>=1;i--) {
	// 	if(p[i].x!=p[i].y) {
	// 		if(p[i].x>p[i].y) d[i][1][2] = 1;
	// 		else d[i][1][2] = 2;
	// 	}
	// 	else d[i][1][2] = d[i+1][1][2];

	// 	if(p[i].x!=p[i].z) {
	// 		if(p[i].x>p[i].z) d[i][1][3] = 1;
	// 		else d[i][1][3] = 3;
	// 	}
	// 	else d[i][1][3] = d[i+1][1][3];

	// 	if(p[i].y!=p[i].z) {
	// 		if(p[i].y>p[i].z) d[i][2][3] = 2;
	// 		else d[i][2][3] = 3;
	// 	}
	// 	else d[i][2][3] = d[i+1][2][3];
	// }
	// int res = 0;
	// for(int i=1;i<=n;i++) {
	// 	if(p[i].x > max(p[i].y,p[i].z) && c[1]<n/2) {
	// 		res += p[i].x;
	// 		c[1] ++;
	// 	}
	// 	else if(p[i].y > max(p[i].x,p[i].z) && c[2]<n/2) {
	// 		res += p[i].y;
	// 		c[2]++;
	// 	}
	// 	else if(p[i].z > max(p[i].x,p[i].y) && c[3]<n/2) {
	// 		res += p[i].z;
	// 		c[3]++;
	// 	}
	// 	else if(p[i].x == p[i].y) {
	// 		if(c[1]<c[2]) 
	// 	}
	// 	else if(p[i].x == p[i].z) {

	// 	}
	// 	else if(p[i].y == p[i].z) {

	// 	}
	// }
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;while(t--)slv();


	return 0;
}