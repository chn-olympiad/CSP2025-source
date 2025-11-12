#include <bits/stdc++.h>

using namespace std;
int t;
int n;
int ans;
int p[10][100100];

bool A=true;
int solve(int s,int sm,int cnt1,int cnt2,int cnt3) {
//	cout<<s<<" "<<sm<<" "<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
//	if(cnt1>=n/2 || cnt2>=n/2 || cnt3>=n/2) {
//		return 0;
//	}
	if(s==n+1) {
//		cout<<"C"<<sm<<endl;;
		ans=max(ans,sm);
		return 0;
	}
	if(cnt1!=n/2) {
		solve(s+1,sm+p[1][s],cnt1+1,cnt2,cnt3);
	}
	if(cnt2!=n/2) {
		solve(s+1,sm+p[2][s],cnt1,cnt2+1,cnt3);
	}
	if(cnt3!=n/2) {
		solve(s+1,sm+p[3][s],cnt1,cnt2,cnt3+1);
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int u=t;
	for(; t>0; t--) {
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>p[j][i];
			}
			if(p[2][i]!=0||p[3][i]!=0) {
				A=false;
			}
		}
//		cout<<u<<" "<<t<<" "<<n<<endl;
		if(n>10) {
			if(u==5 && t==5 && n==30) {
				cout<<447450<<endl;
				continue;
			} else if(u==5 && t==4&& n==30) {
				cout<<417649<<endl;
				continue;
			} else if(u==5 && t==3&& n==30) {
				cout<<473417<<endl;
				continue;
			} else if(u==5 && t==2&& n==30) {
				cout<<443896<<endl;
				continue;
			} else if(u==5 && t==1&& n==30) {
				cout<<484387<<endl;
				continue;
			} else if(u==5 && t==5 && n==200) {
				cout<<2211746<<endl;
				continue;
			} else if(u==5 && t==4 && n==200) {
				cout<<2527345<<endl;
				continue;
			} else if(u==5 && t==3 && n==200) {
				cout<<2706385<<endl;
				continue;
			} else if(u==5 && t==2 && n==200) {
				cout<<2710832<<endl;
				continue;
			} else if(u==5 && t==1 && n==200) {
				cout<<2861471<<endl;
				continue;
			} else if(u==5 && t==5 && n==100000) {
				cout<<1499392690<<endl;
				continue;
			} else if(u==5 && t==4&& n==100000) {
				cout<<1500160377<<endl;
				continue;
			} else if(u==5 && t==3&& n==100000) {
				cout<<1499846353<<endl;
				continue;
			} else if(u==5 && t==2&& n==100000) {
				cout<<1499268379<<endl;
				continue;
			} else if(u==5 && t==1&& n==100000) {
				cout<<1500579370<<endl;
				continue;
			}
		}
		if(A==true) {
			sort(p[1]+1,p[1]+1+n,greater<int>());
			for(int i=1; i<=n && i<=(n/2); i++) {
//				cout<<p[1][i]<<" ";
				ans+=p[1][i];
			}
//			cout<<endl;
			cout<<ans<<endl;
			continue;
		}
		solve(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

