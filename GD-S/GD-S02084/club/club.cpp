#include<bits/stdc++.h>
using namespace std;
bool A=1,B=1;
int n;
struct peo {
	int a[5],afri,asec,athi;
} p[10005];
bool cmp(peo x,peo y) {
	if(x.afri!=1)return 0;
	if(y.afri!=1)return 1;
	if(x.a[1]==y.a[1])
		return x.a[2]<y.a[2];
	return x.a[1]>y.a[1];
}
bool cmp2(peo x,peo y) {
	if(x.afri==3)return 0;
	if(y.afri==3)return 1;
	return x.a[2]>y.a[2];
}
bool cmp3(peo x,peo y) {
	if(x.afri!=3)return 0;
	if(y.afri!=3)return 1;
	return x.a[3]>y.a[3];
}
bool cmpe(peo x,peo y) {
	return x.a[2]>y.a[2];
}
void pt(int i) {
//	cout<<i<<' '<<p[i].a[1]<<' '<<p[i].a[2]<<endl;
}
int qj(int a,int b,int c,int i) {
	if(a>n/2||b>n/2||c>n/2)return INT_MIN;
	if(i>n)return 0;
	int ans=0;
	ans=ans+max(max(qj(a+1,b,c,i+1)+p[i].a[1],qj(a,b+1,c,i+1)+p[i].a[2]),qj(a,b,c+1,i+1)+p[i].a[3]);
	return ans;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		A=1,B=1;
		int tmp1=0,tmp2=0,tmp3=0,ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
			if(p[i].a[3]!=0) {
				A=0,B=0;
			}
			if(p[i].a[2]!=0) {
				A=0;
			}
			if(p[i].a[1]>p[i].a[2]) {
				if(p[i].a[1]>p[i].a[3]) {
					p[i].afri=1;
					if(p[i].a[2]>p[i].a[3]) {
						p[i].asec=2;
						p[i].athi=3;
					} else {
						p[i].asec=3;
						p[i].athi=2;
					}
				} else {
					p[i].afri=3;
					p[i].asec=1;
					p[i].athi=2;
				}
			} else {
				if(p[i].a[2]>p[i].a[3]) {
					p[i].afri=2;
					if(p[i].a[1]>p[i].a[3]) {
						p[i].asec=1;
						p[i].athi=3;
					} else {
						p[i].asec=3;
						p[i].athi=1;
					}
				} else {
					p[i].afri=3;
					p[i].asec=2;
					p[i].athi=1;
				}
			}
		}
		if(n>19) {
			if(A==1) {
				sort(p+1,p+n+1,cmp);
				tmp1=n/2+1;
				for(int i=1; i<=n/2; i++) {
					if(p[i].afri!=1) {
						tmp1=i;
						break;
					}
					ans+=p[i].a[1];
					pt(i);
				}
				cout<<ans<<endl;
				continue;
			} else if(B==1) {
				vector<long long> dp(n+100);
				int tot=0,ans=0;
				srand(time(0));
//				for(int i=2;i<n;i++){
//					swap(p[i],p[rand()%(n-1)+1]);
//				}
				for(int i=1; i<=n; i++) {
					
					for(int j=tot+1; j>0; j--) {
						if(i-j<=n/2) {
							if(j<=n/2) {
								if(dp[j]+p[i].a[2]<dp[j-1]+p[i].a[1]) {
									tot=max(tot,j);
									dp[j]=dp[j-1]+p[i].a[1];
								} else {
									dp[j]=dp[j]+p[i].a[2];
								}
							} else {
								dp[j]=dp[j]+p[i].a[2];
							}
						} else if(j<=n/2) {
							tot=max(tot,j);
							dp[j]=dp[j-1]+p[i].a[1];
						}

					}
//					if(tot+1<=n/2) {
//							dp[tot+1]=dp[tot]+p[i].a[1];
//							tot++;
//					}
				}
				if(dp[n/2])
				cout<<dp[n/2]<<endl;
				else{
					cout<<max(dp[n/2-1],dp[n/2+1]);
				}
			}
		} else {
			cout<<qj(0,0,0,1)<<endl;
		}
	}
	return 0;
}
