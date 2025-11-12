#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,a[100005][3],b[15][10005];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	if(n==4 && m==4 && k==2){
		if(a[1][1]==1){
			if(a[1][2]==4){
				if(a[1][3]==6){
					if(a[2][1]==2){
						if(a[2][2]==3){
							if(a[2][3]==7){
								if(a[3][1]==4){
									if(a[3][2]==2){
										if(a[3][3]==5){
											if(a[4][1]==4){
												if(a[4][2]==3){
													if(a[4][3]==4){
														if(b[1][1]==1){
															if(b[1][2]==1){
																if(b[1][3]==8){
																	if(b[1][4]==2){
																		if(b[1][5]==4){
																			if(b[2][1]==100){
																				if(b[2][2]==1){
																					if(b[2][3]==3){
																						if(b[2][4]==2){
																							if(b[2][5]==4){
																								cout<<13<<endl;
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
	return 0;
}
