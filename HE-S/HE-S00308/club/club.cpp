#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t;
int a[N][4];
int cnt[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		//ÊäÈë 
		int n;
		cin>>n;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n==2){
			int mx = 0;
			for(int r1 = 1;r1<=3;r1++){
				memset(cnt,0,sizeof(cnt));
				cnt[r1]++;
				for(int r2 = 1;r2<=3;r2++){
					cnt[r2]++;
					if(cnt[1]<= n/2 && cnt[2]<=n/2&&cnt[3]<=n/2){
						mx = max(mx,a[1][r1]+a[2][r2]);
					}
				}
			}
			cout<<mx<<'\n';
		}else if(n==4){
			int mx = 0;
			for(int r1 = 1;r1<=3;r1++){
				memset(cnt,0,sizeof(cnt));
				cnt[r1]++;
				for(int r2 = 1;r2<=3;r2++){
					memset(cnt,0,sizeof(cnt));
					cnt[r2]++;
					for(int r3 = 1;r3<=3;r3++){
						cnt[r3]++;
						for(int r4 = 1;r4<=3;r4++){
							cnt[r4]++;
//							cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<'\n'; 
							if(cnt[1]<= n/2 && cnt[2]<=n/2&&cnt[3]<=n/2){
								mx = max(mx,a[1][r1]+a[2][r2]+a[3][r3]+a[4][r4]);
							} 
						}
					}
				}
			}
			cout<<mx<<'\n';
		}else if(n==10){
			int mx = 0;
			for(int r1 = 1;r1<=3;r1++){
				memset(cnt,0,sizeof(cnt));
				cnt[r1]++;
				for(int r2 = 1;r2<=3;r2++){
					memset(cnt,0,sizeof(cnt));
					cnt[r2]++;
					for(int r3 = 1;r3<=3;r3++){
						memset(cnt,0,sizeof(cnt));
						cnt[r3]++;
						for(int r4 = 1;r4<=3;r4++){
							memset(cnt,0,sizeof(cnt));
							cnt[r4++];
							for(int r5 = 1;r5<=3;r5++){
								memset(cnt,0,sizeof(cnt));
								cnt[r5++];
								for(int r6 = 1;r6<=3;r6++){
									cnt[r6++];
									for(int r7 = 1;r7<=3;r7++){
										cnt[r7++];
										for(int r8 = 1;r8<=3;r8++){
											cnt[r8++];
											for(int r9 = 1;r9<=3;r9++){
												cnt[r9++];
												for(int r10 = 1;r10<=3;r10++){
													cnt[r10++];
													if(cnt[1]<= n/2 && cnt[2]<=n/2&&cnt[3]<=n/2){
														mx = max(mx,a[1][r1]+a[2][r2]+a[3][r3]+a[4][r4]+a[5][r5]+a[6][r6]+a[7][r7]+a[8][r8]+a[9][r9]+a[10][r10]);
													} 
												}	
											}
										}
									}
								}
							}
						}
					}
				}
			} 
			cout<<mx<<'\n';			
		}
	}	
	return 0;
}
