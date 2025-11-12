#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define x first
#define y second
#define vt vector
#define pb push_back
using namespace std;
const int N=1e6+10;
const int M=1e3+10;
const int INF=0x3f3f3f3f;
ll n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int a1=0;a1<=1;a1++){
		for(int a2=0;a2<=1;a2++){
			for(int a3=0;a3<=1;a3++){
				for(int a4=0;a4<=1;a4++){
					for(int a5=0;a5<=1;a5++){
						for(int a6=0;a6<=1;a6++){
							for(int a7=0;a7<=1;a7++){
								for(int a8=0;a8<=1;a8++){
									for(int a9=0;a9<=1;a9++){
										for(int a10=0;a10<=1;a10++){
											for(int a11=0;a11<=1;a11++){
												for(int a12=0;a12<=1;a12++){
													for(int a13=0;a13<=1;a13++){
														for(int a14=0;a14<=1;a14++){
															for(int a15=0;a15<=1;a15++){
																for(int a16=0;a16<=1;a16++){
																	for(int a17=0;a17<=1;a17++){
																		for(int a18=0;a18<=1;a18++){
																			for(int a19=0;a19<=1;a19++){
																				for(int a20=0;a20<=1;a20++){
																					ll maxx=-INF,cnt=0,num=0;
																					if(a1==1)maxx=max(maxx,a[1]),cnt+=a[1],num++;
																					if(a2==1)maxx=max(maxx,a[2]),cnt+=a[2],num++;
																					if(a3==1)maxx=max(maxx,a[3]),cnt+=a[3],num++;
																					if(a4==1)maxx=max(maxx,a[4]),cnt+=a[4],num++;
																					if(n<4&&a4==1)break;
																					if(a5==1)maxx=max(maxx,a[5]),cnt+=a[5],num++;
																					if(n<5&&a5==1)break;
																					if(a6==1)maxx=max(maxx,a[6]),cnt+=a[6],num++;
																					if(n<6&&a6==1)break;
																					if(a7==1)maxx=max(maxx,a[7]),cnt+=a[7],num++;
																					if(n<7&&a7==1)break;
																					if(a8==1)maxx=max(maxx,a[8]),cnt+=a[8],num++;
																					if(n<8&&a8==1)break;
																					if(a9==1)maxx=max(maxx,a[9]),cnt+=a[9],num++;
																					if(n<9&&a9==1)break;
																					if(a10==1)maxx=max(maxx,a[10]),cnt+=a[10],num++;
																					if(n<10&&a10==1)break;
																					if(a11==1)maxx=max(maxx,a[11]),cnt+=a[11],num++;
																					if(n<11&&a11==1)break;
																					if(a12==1)maxx=max(maxx,a[12]),cnt+=a[12],num++;
																					if(n<12&&a12==1)break;
																					if(a13==1)maxx=max(maxx,a[13]),cnt+=a[13],num++;
																					if(n<13&&a13==1)break;
																					if(a14==1)maxx=max(maxx,a[14]),cnt+=a[14],num++;
																					if(n<14&&a14==1)break;
																					if(a15==1)maxx=max(maxx,a[15]),cnt+=a[15],num++;
																					if(n<15&&a15==1)break;
																					if(a16==1)maxx=max(maxx,a[16]),cnt+=a[16],num++;
																					if(n<16&&a16==1)break;
																					if(a17==1)maxx=max(maxx,a[17]),cnt+=a[17],num++;
																					if(n<17&&a17==1)break;
																					if(a18==1)maxx=max(maxx,a[18]),cnt+=a[18],num++;
																					if(n<18&&a18==1)break;
																					if(a19==1)maxx=max(maxx,a[19]),cnt+=a[19],num++;
																					if(n<19&&a19==1)break;
																					if(a20==1)maxx=max(maxx,a[20]),cnt+=a[20],num++;
																					if(n<20&&a20==1)break;
																					if(cnt>maxx*2&&num>=3){
																						ans++;
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
	cout<<ans;
	return 0; 
}
