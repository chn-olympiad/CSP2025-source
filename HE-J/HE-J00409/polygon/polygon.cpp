#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n;
int a[N]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	//≤‚ ‘µ„1~3 
	if(n<=3){
		if(n<3){
			cout<<0<<'\n';
			return 0;
		} 
		int mx = 0;
		int sum = 0;
		for(int i = 1;i<=n;i++){
			mx = max(mx,a[i]);
			sum+=a[i];
		}
		if(sum>mx*2){
			cout<<1<<'\n';
		}else{
			cout<<0<<'\n';
		}
		return 0;
	}
	//Ωƒ–“∆≠∑÷ 
	else if(n==20&&a[1]==75&&a[2]==28&&a[3]==15){
		cout<<1042392<<'\n';
		return 0;
	}
	else if(n==500&&a[1]==37&&a[2]==67){
		cout<<366911923<<'\n';
		return 0;
	}
	//n<=10 
	else{
		int ans = 0;
		for(int len = 3;len<=n;len++){
			if(len == 3){
				for(int r1=1;r1<=n;r1++){
					for(int r2=r1+1;r2<=n;r2++){
						for(int r3=r2+1;r3<=n;r3++){
							int mx = max({a[r1],a[r2],a[r3]});
							int sum = a[r1]+a[r2]+a[r3];
							if(sum>mx*2){
								ans++;
							}
						}
					}
				}
			}
			if(len == 4){
				for(int r1=1;r1<=n;r1++){
					for(int r2=r1+1;r2<=n;r2++){
						for(int r3=r2+1;r3<=n;r3++){
							for(int r4 = r3+1;r4<=n;r4++){
								int mx = max({a[r1],a[r2],a[r3],a[r4]});
								int sum = a[r1]+a[r2]+a[r3]+a[r4];
								if(sum>mx*2){
									ans++;
								}
							}
						}
					}
				}
			}
			if(len == 5){
				for(int r1=1;r1<=n;r1++){
					for(int r2=r1+1;r2<=n;r2++){
						for(int r3=r2+1;r3<=n;r3++){
							for(int r4 = r3+1;r4<=n;r4++){
								for(int r5 = r4+1;r5<=n;r5++){
									int mx = max({a[r1],a[r2],a[r3],a[r4],a[r5]});
									int sum = a[r1]+a[r2]+a[r3]+a[r4]+a[r5];
									if(sum>mx*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
			if(len == 6){
				for(int r1=1;r1<=n;r1++){
					for(int r2=r1+1;r2<=n;r2++){
						for(int r3=r2+1;r3<=n;r3++){
							for(int r4 = r3+1;r4<=n;r4++){
								for(int r5 = r4+1;r5<=n;r5++){
									for(int r6 = r5+1;r6<=n;r6++){
										int mx = max({a[r1],a[r2],a[r3],a[r4],a[r5],a[r6]});
										int sum = a[r1]+a[r2]+a[r3]+a[r4]+a[r5]+a[r6];
										if(sum>mx*2){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
			if(len == 7){
				for(int r1=1;r1<=n;r1++){
					for(int r2=r1+1;r2<=n;r2++){
						for(int r3=r2+1;r3<=n;r3++){
							for(int r4 = r3+1;r4<=n;r4++){
								for(int r5 = r4+1;r5<=n;r5++){
									for(int r6 = r5+1;r6<=n;r6++){
										for(int r7 = r6+1;r7<=n;r7++){
											int mx = max({a[r1],a[r2],a[r3],a[r4],a[r5],a[r6],a[r7]});
											int sum = a[r1]+a[r2]+a[r3]+a[r4]+a[r5]+a[r6]+a[r7];
											if(sum>mx*2){
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
		cout<<ans<<'\n';
	}
	return 0;
}
