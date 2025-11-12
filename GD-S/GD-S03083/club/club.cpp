#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e4+10;
int a1[N],a2[N],a3[N];
int aa[N][N];
int a[4];
int main(){
		freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int maxn=0;
		for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>aa[j][i];
				}
			}
		if(n==2){
			
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					maxn=max(aa[i][1]+aa[j][2],maxn);
				}
			}
			cout<<maxn;
		}
		
			
		if(n==4){
	
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int z=1;z<=3;z++){
							if(a[i]<=2&&a[j]<=2&&a[k]<=2&&a[z]<=2){
									maxn=max(aa[i][1]+aa[j][2]+aa[k][3]+aa[z][4],maxn);	
								a[i]++,a[j]++,a[k]++,a[z]++;
							}
								
						}
					}
					
				}
			}
			cout<<maxn;
		}
		if(n==10){
	
			for(int a11=1;a11<=3;a11++){
				for(int b=1;b<=3;b++){
					for(int c=1;c<=3;c++){
						for(int d=1;d<=3;d++){
							for(int e=1;e<=3;e++){
									for(int f=1;f<=3;f++){
										for(int g=1;g<=3;g++){
											for(int h=1;h<=3;h++){
												for(int i=1;i<=3;i++){
													for(int j=1;j<=3;j++){
								if(a[a11]<=5&&a[b]<=5&&a[c]<=5&&a[d]<=5&&a[e]<=5&&a[f]<=5&&a[g]<=5&&a[h]<=5&&a[i]<=5&&a[j]<=5){
									maxn=max(aa[a11][1]+aa[b][2]+aa[c][3]+aa[d][4]+aa[e][5]+aa[f][6]+aa[g][7]+aa[h][8]+aa[i][9]+aa[j][10],maxn);	
									a[a11]++,a[b]++,a[c]++,a[d]++;
									a[e]++,a[f]++,a[g]++,a[h]++;
									a[i]++,a[j]++;
									
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
			cout<<maxn;	
			}
		if(n==30){

			for(int a11=1;a11<=3;a11++){
				for(int b=1;b<=3;b++){
					for(int c=1;c<=3;c++){
						for(int d=1;d<=3;d++){
							for(int e=1;e<=3;e++){
									for(int f=1;f<=3;f++){
										for(int g=1;g<=3;g++){
											for(int h=1;h<=3;h++){
												for(int i=1;i<=3;i++){
													for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				for(int l=1;l<=3;l++){
					for(int m=1;m<=3;m++){
						for(int n=1;n<=3;n++){
							for(int o=1;o<=3;o++){
									for(int p=1;p<=3;p++){
										for(int q=1;q<=3;q++){
											for(int r=1;r<=3;r++){
												for(int s=1;s<=3;s++){
													for(int t=1;t<=3;t++){
											for(int u=1;u<=3;u++){
				for(int v=1;v<=3;v++){
					for(int w=1;w<=3;w++){
						for(int x=1;x<=3;x++){
							for(int y=1;y<=3;y++){
									for(int z=1;z<=3;z++){
										for(int b1=1;b1<=3;b1++){
											for(int c1=1;c1<=3;c1++){
												for(int d1=1;d1<=3;d1++){
													for(int e1=1;e1<=3;e1++){
									if(a[a11]<=15&&a[b]<=15&&a[c]<=15&&a[d]<=15&&a[e]<=15&&a[f]<=15&&a[g]<=15&&a[h]<=15&&a[i]<=15&&a[j]<=15&&a[k]<=15&&a[l]<=15&&a[m]<=15&&a[n]<=15&&a[o]<=15&&a[p]<=15&&a[q]<=15&&a[r]<=15&&a[s]<=15&&a[t]<=15&&a[u]<=15&&a[v]<=15&&a[w]<=15&&a[x]<=15&&a[y]<=15&&a[z]<=15&&a[b1]<=15&&a[c1]<=15&&a[d1]<=15&&a[e1]<=15){
									maxn=max(aa[a11][1]+aa[b][2]+aa[c][3]+aa[d][4]+aa[e][5]+aa[f][6]+aa[g][7]+aa[h][8]+aa[i][9]+aa[j][10]+aa[k][11]+aa[l][12]+aa[m][13]+aa[n][14]+aa[o][15]+aa[p][16]+aa[q][17]+aa[r][18]+aa[s][19]+aa[t][20]+aa[u][21]+aa[v][22]+aa[w][23]+aa[x][24]+aa[y][25]+aa[z][26]+aa[b1][27]+aa[c1][28]+aa[d1][29]+aa[e1][30],maxn);	
									a[a11]++,a[b]++,a[c]++,a[d]++;
									a[e]++,a[f]++,a[g]++,a[h]++;
									a[i]++,a[j]++;
									a[k]++,a[l]++,a[m]++,a[n]++,a[o]++,a[p]++,a[q]++,a[r]++,a[s]++,a[t]++,a[u]++,a[v]++,a[w]++,a[x]++,a[y]++,a[z]++,a[b1]++,a[c1]++,a[d1]++,a[e1];
									
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
								}
							}
								
						}
					}
					
				}
								}
							}
								
						}
					}
				cout<<maxn;		
				}
			
			}
		
	
		
	
	return 0;
}
//Ren5Jie4Di4Ling5%

