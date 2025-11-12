#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	int s[20001][20001],a[20001][20001];
	int n;
	int t;
	int ans=0,cnt=0,haha=10;
	int num=1;
	int cnt1=0,cnt2=0,cnt3=0;
	cin>>n>>t;
		while(n--) {
			for(int i=1; i<=t; i++) {
				for(int j=1; j<=3; j++) {
					cin>>s[i][j];
					a[i][j]=s[i][j];
				}
			}
			for(int i=1; i<=t; i++) {
				for(int j=1; j<3; j++) {
					int b=s[i][1];
					if(b<s[i][j+1]) {
						a[i][j]=num;
						num++;

					} else {
						a[i][j+1]=num;
						num++;
					}
				}
			}

			for(int i=1; i<=t; i++) {
				for(int j=1; j<=3; j++) {
					if(a[i][j]=3) {
						ans+=s[i][j];
						if(j=1)cnt1++;
						if(j=2)cnt2++;
						if(j=3)cnt3++;
					}
				}
			}
			if(cnt1<=t/2&&cnt2<=t/2&&cnt3<=t/2) {
				cout<<ans<<endl;
			} else {
				while(cnt1>t/2||cnt2>t/2||cnt3>t/2) {
					if(cnt1>0) {
						for(int i=1; i<=t; i++) {
							for(int j=1; j<=3; j++) {
								if(a[i][j]=2) {
									int b=min(haha,s[i][j]);
									ans-=s[i][1];
									cnt1--;
									if(j=2) {
										ans+=s[i][j];
										cnt2++;
									}
									if(j=3) {
										ans+=s[i][j];
										cnt3++;
									}
								}
							}
						}
					}

					if(cnt2>0) {
						for(int i=1; i<=t; i++) {
							for(int j=1; j<=3; j++) {
								if(a[i][j]=2) {
									int b=min(haha,s[i][j]);
									ans-=s[i][2];
									cnt2--;
									if(j=1) {
										ans+=s[i][j];
										cnt1++;
									}
									if(j=3) {
										ans+=s[i][j];
										cnt3++;
									}
								}
							}
						}

					}
					if(cnt3>0) {
						for(int i=1; i<=t; i++) {
							for(int j=1; j<=3; j++) {
								if(a[i][j]=2) {
									int b=min(haha,s[i][j]);
									ans-=s[i][3];
									cnt3--;
									if(j=1) {
										ans+=s[i][j];
										cnt1++;
									}
									if(j=2) {
										ans+=s[i][j];
										cnt2++;
									}
								}
							}
						}

					}
				}
				cout<<ans<<endl;
			}
		}

	return 0;
}
