#include<bits/stdc++.h>
using namespace std;
int n,s,d,a[100005][4],t,s1,s2;
bool cmp(int z,int x){
	return z>x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		d=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]==0&&a[i][3]==0){
				s++;
			}else if(a[i][1]==0&&a[i][3]==0){
				s1++;
			}else if(a[i][1]==0&&a[i][2]==0){
				s2++;
			}
		}
		if(s==n||s1==n||s2==n){
			int b[100005];
			if(s==n){
				for(int i=1;i<=n;i++){
					b[i]=a[i][1];
				}
			}else if(s1==n){
				for(int i=1;i<=n;i++){
					b[i]=a[i][2];
				}
			}else if(s2==n){
				for(int i=1;i<=n;i++){
					b[i]=a[i][3];
				}
			}
			sort(b+1,b+n+1,cmp);
			s=0;
			for(int i=1;i<=n/2;i++){
				s+=b[i];
			}
			cout<<s<<endl;
		}else if(n==2){
			s=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						s=a[1][i]+a[2][j];
						d=max(d,s);
						s=0;
					}
				}
			}
			cout<<d<<endl;
		}else if(n==4){
			s=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							if(!(i==j&&j==k||i==j&&i==l||j==k&&k==l||i==k&&k==l)){
								s=a[1][i]+a[2][j]+a[3][k]+a[4][l];
								d=max(s,d);
								s=0;
							}
						}
					}
				}
			}
			cout<<d<<endl;
		}else if(n==10){//ansdt
			int v[4];
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							for(int m=1;m<=3;m++){
								for(int o=1;o<=3;o++){
									for(int p=1;p<=3;p++){
										for(int q=1;q<=3;q++){
											for(int r=1;r<=3;r++){
												for(int u=1;u<=3;u++){
													v[i]++;
													v[j]++;
													v[k]++;
													v[l]++;
													v[m]++;
													v[o]++;
													v[p]++;
													v[q]++;
													v[r]++;
													v[u]++;
													if(v[1]<=5&&v[2]<=5&&v[3]<=5){
														s=a[1][i]+a[2][j]+a[3][k]+a[4][l]+a[5][m]+a[6][o]+a[7][p]+a[8][q]+a[9][r]+a[10][u];
														d=max(s,d);
														s=0;
													}
													v[1]=0;
													v[2]=0;
													v[3]=0;
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
			cout<<d<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
