#include<bits/stdc++.h>
using namespace std;
long long a[100005][5],b[3],c[100005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		long long sum1=0,sum3=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) scanf("%lld",&a[i][j]);
			sum1=sum1+a[i][1];
			sum3=sum3+a[i][3];
		}
		if(n==2){
			long long maxn=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j) maxn=max(a[1][i]+a[2][j],maxn);
				}
			}
			cout<<maxn<<endl;
		}else if(n==4){
			long long maxn=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int g=1;g<=3;g++){
							b[i]++;b[j]++;b[k]++;b[g]++;
							if(b[i]<=2&&b[j]<=2&&b[k]<=2&&b[g]<=2) maxn=max(a[1][i]+a[2][j]+a[3][k]+a[4][g],maxn);
							b[i]=b[j]=b[k]=b[g]=0;
						}
					}
				}
			}
			cout<<maxn<<endl;
		}else if(n==10){
			long long maxn=-1;
			for(int i1=1;i1<=3;i1++){
				for(int i2=1;i2<=3;i2++){
					for(int i3=1;i3<=3;i3++){
						for(int i4=1;i4<=3;i4++){
							for(int i5=1;i5<=3;i5++){
								for(int i6=1;i6<=3;i6++){
									for(int i7=1;i7<=3;i7++){
										for(int i8=1;i8<=3;i8++){
											for(int i9=1;i9<=3;i9++){
												for(int i10=1;i10<=3;i10++){
													b[i1]++;b[i2]++;b[i3]++;b[i4]++;b[i5]++;b[i6]++;b[i7]++;b[i8]++;b[i9]++;b[i10]++;
													if(b[i1]<=5&&b[i2]<=5&&b[i3]<=5&&b[i4]<=5&&b[i5]<=5&&b[i6]<=5&&b[i7]<=5&&b[i8]<=5&&b[i9]<=5&&b[i10]<=5) maxn=max(a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]+a[10][i10],maxn);
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
			cout<<maxn<<endl;	
		}else if(sum1==0&&sum3==0){
			sort(c+1,c+n+1,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum=sum+c[i];
			}
			cout<<sum<<endl;
		}else{
			long long sum=0;
			for(int i=1;i<=n;i++){
				sum=sum+max(max(a[i][1],a[i][2]),a[i][3]);
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
