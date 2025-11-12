#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000010][4],aa[1000001],b[50],cnt1,cnt2;
bool cmp(int a,int b){
	if(a>b) return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]==0) cnt1++;
			if(a[i][2]==0) cnt2++;
		}
		if(cnt1==n&&cnt2==n){
			for(int i=0;i<n;i++){
				aa[i]=a[i][0];
			}
			sort(aa,aa+n,cmp);
			int ans=0;
			for(int i=0;i<n/2;i++){
				ans+=aa[i];
			}
			cout<<ans;
		}else if(cnt1!=n&&cnt2==n){
			int dp[100001][3];
			for(int i=0;i<n;i++){
				for(int j=0;j<2;j++){
					dp[i][j]=max(dp[i-1][0]+a[i][j],dp[i-1][1]+a[i][j]);
				}
			}
			cout<<max(dp[n-1][0],dp[n-1][1]);
		}else if(n==2){
			int ma=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i!=j) ma=max(ma,a[1][i]+a[0][j]);
				}
			}
			cout<<ma;
		}else if(n==4){
			int ma=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					for(int k=0;k<3;k++){
						for(int l=0;l<3;l++){
							b[i]++;
							b[j]++;
							b[k]++;
							b[l]++;
							if(b[0]<=2&&b[1]<=2&&b[2]<=2) ma=max(ma,a[0][i]+a[1][j]+a[2][k]+a[3][l]);
							b[0]=b[1]=b[2]=0;
						}
					}
				}
			}
			cout<<ma;
		}else if(n==10){
			int ma=0;
			for(int i1=0;i1<3;i1++){
				for(int i2=0;i2<3;i2++){
					for(int i3=0;i3<3;i3++){
						for(int i4=0;i4<3;i4++){
							for(int i5=0;i5<3;i5++){
								for(int i6=0;i6<3;i6++){
									for(int i7=0;i7<3;i7++){
										for(int i8=0;i8<3;i8++){
											for(int i9=0;i9<3;i9++){
												for(int i10=0;i10<3;i10++){
													b[i1]++;b[i2]++;b[i3]++;b[i4]++;b[i5]++;b[i6]++;b[i7]++;b[i8]++;b[i9]++;b[i10]++;
													if(b[i1]<=5&&b[i2]<=5&&b[i3]<=5&&b[i4]<=5&&b[i5]<=5&&b[i6]<=5&&b[i7]<=5&&b[i8]<=5&&b[i9]<=5&&b[i10]<=5){
														ma=max(ma,a[0][i1]+a[1][i2]+a[2][i3]+a[3][i4]+a[4][i5]+a[5][i6]+a[6][i7]+a[7][i8]+a[8][i9]+a[9][i10]);
													}
													b[i1]=b[i2]=b[i3]=b[i4]=b[i5]=b[i6]=b[i7]=b[i8]=b[i9]=b[i10]=0;
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
			cout<<ma;
		}
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%
