#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
ll T,n,a[N][5],A[N],ans=0;
bool cmpA(ll p,ll q){
	return p > q;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		cin >> n;
		if(n==2) // n==2
		{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin >> a[i][j];
				} 
			}
			for(int j1=1;j1<=3;j1++){
				for(int j2=1;j2<=3;j2++){
					if(j1==j2) continue;
					ans=max(ans,a[1][j1]+a[2][j2]);
				}
			}
			cout << ans << endl;
			continue;
		}
		if(n==4) //n==4
		{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin >> a[i][j];
				} 
			}
			int cnt[5];
			for(int j1=1;j1<=3;j1++){
				for(int j2=1;j2<=3;j2++){
					for(int j3=1;j3<=3;j3++){
						for(int j4=1;j4<=3;j4++){
							memset(cnt,0,sizeof(cnt));
							cnt[j1]++,cnt[j2]++,cnt[j3]++,cnt[j4]++;
							if(cnt[1]>2 || cnt[2]>2 || cnt[3]>2) continue;
							ans=max(ans,a[1][j1]+a[2][j2]+a[3][j3]+a[4][j4]);
						} 
					}
				}
			}
			cout << ans << endl;
			continue;
		}
		if(n==10) // n==10
		{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin >> a[i][j];
				} 
			}
			int cnt[5];
			for(int j1=1;j1<=3;j1++){
				for(int j2=1;j2<=3;j2++){
					for(int j3=1;j3<=3;j3++){
						for(int j4=1;j4<=3;j4++){
							for(int j5=1;j5<=3;j5++){
								for(int j6=1;j6<=3;j6++){
									for(int j7=1;j7<=3;j7++){
										for(int j8=1;j8<=3;j8++){
											for(int j9=1;j9<=3;j9++){
												for(int j10=1;j10<=3;j10++){
													memset(cnt,0,sizeof(cnt));
													cnt[j1]++,cnt[j2]++,cnt[j3]++,cnt[j4]++,cnt[j5]++,cnt[j6]++,cnt[j7]++,cnt[j8]++,cnt[j9]++,cnt[j10]++;
													if(cnt[1]>5 || cnt[2]>5 || cnt[3]>5) continue;
													ans=max(ans,a[1][j1]+a[2][j2]+a[3][j3]+a[4][j4]+a[5][j5]+a[6][j6]+a[7][j7]+a[8][j8]+a[9][j9]+a[10][j10]);
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
			cout << ans << endl;
			continue;
		}
		memset(A,0,sizeof(A)); // A
		ll sum2=0,sum3=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
				if(j==2) sum2+=a[i][j];
				if(j==3) sum3+=a[i][j];
			}
			A[i]=a[i][1];
		}
		if(sum2==0 && sum3==0) 
		{
			sort(A+1,A+n+1,cmpA);
			for(int i=1;i<=n/2;i++)
			{
				ans+=A[i];
			}
			cout << ans << endl;
		}
	}
	return 0;
}
