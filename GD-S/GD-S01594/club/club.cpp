#include<bits/stdc++.h>
using namespace std;

long long f[102][102][102];

long long e[100005][4];

long long max(long long a,long long b) {
	if(a>b) return a;
	return b;
}

long long Max(long long a,long long b,long long c) {
	return max(max(a,b),c);
}

long long tmpa[100005];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int TTT=1;TTT<=T;TTT++) {
		int n;
		cin>>n;
		bool flag_2=0,flag_3=0;
		for(int i=1;i<=n;i++) {
			scanf("%lld%lld%lld",&e[i][1],&e[i][2],&e[i][3]);
			if(e[i][2]!=0) flag_2=1;
			if(e[i][3]!=0) flag_3=1;
		}
		
		if(flag_2==0&&flag_3==0) {
			for(int i=1;i<=n;i++) tmpa[i]=e[i][1];
			sort(tmpa+1,tmpa+1+n);
//			for(int i=1;i<=n;i++) cout<<tmpa[i]<<" ";
//			cout<<endl;
			long long cnt=0;
			for(int i=(n/2)+1;i<=n;i++) {
				cnt+=tmpa[i];
			}
			cout<<cnt<<endl;
			continue;
		}
		
		for(int i=0;i<=n;i++) {
			for(int a=n/2;a>=0;a--) {
				for(int b=n/2;b>=0;b--) {
					for(int c=n/2;c>=0;c--) {
						f[a][b][c]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++) {
			for(int a=n/2;a>=0;a--) {
				for(int b=n/2;b>=0;b--) {
					for(int c=n/2;c>=0;c--) {
						if(a==0&&b==0&&c==0) continue;
						else if(a==0&&b==0&&c!=0) f[a][b][c]=f[a][b][c-1]+e[i][3];
						else if(a==0&&c==0&&b!=0) f[a][b][c]=f[a][b-1][c]+e[i][2];
						else if(b==0&&c==0&&a!=0) f[a][b][c]=f[a-1][b][c]+e[i][1];
						else if(a==0&&b!=0&&c!=0) {
							f[a][b][c]=max(f[a][b-1][c]+e[i][2],
											  f[a][b][c-1]+e[i][3]);
						}
						else if(b==0&&a!=0&&c!=0) {
							f[a][b][c]=max(f[a-1][b][c]+e[i][1],
											  f[a][b][c-1]+e[i][3]);
						}
						else if(c==0&&a!=0&&b!=0) {
							f[a][b][c]=max(f[a-1][b][c]+e[i][1],
											  f[a][b-1][c]+e[i][2]);
						}
						
						 else f[a][b][c]=Max(f[a-1][b][c]+e[i][1],
											    f[a][b-1][c]+e[i][2],
											  	f[a][b][c-1]+e[i][3]);
					}
				}
			}
		}
		printf("%lld\n",f[n/2][n/2][n/2]);
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

18
4
13
*/
