#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
# define N 100010
int t, n, a[3][N], ans = 0, m = 0;
//int c11 = 1, c22 = 1, c33 = 1;

int main(){freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1; i <= t; ++i){cin >> n;
		int o = n/2;
		int c1[o+3] = {0}, c2[o+3] = {0}, c3[o+3] = {0};
		
		for(int j = 1; j <= n; ++j){
			cin >> a[1][j] >> a[2][j] >> a[3][j];
		}
		
		for(int i = 1; i <= n; ++i){
			m = 0;
			m = max(a[1][i], a[2][i]);
			m = max(m , a[3][i]);
			if(m == a[1][i]){
				//if(c11 == o+1){
					sort(c1+1, c1+o+1);
					//c11 = 1;
					
					if(m > c1[1]){
					ans -= c1[1];
					ans += m;
					c1[1] = m;
					//c11++;
					}
					else{
					int x = 0;
					x = max(a[1][i-1]+a[2][i], a[1][i-1]+a[3][i]);
					x = max(a[2][i-1]+a[1][i], x);
					x = max(x, a[3][i-1]+a[1][i]);
					if(x==a[1][i-1]+a[2][i]){
							sort(c2+1, c2+o+1);
				//			c22 = 1;
						if(m > c2[1]){
							ans -= c2[1];
							ans += m;
							c2[1] = m;
							}
						}
					else if(x==a[1][i-1]+a[3][i]){sort(c3+1, c3+o+1);
					//c33 = 1;
				//}
						if(m > c3[1]){
							ans -= c3[1];
							ans += m;
						c3[1] = m;
						//c33++;
						}
					}
					
					else if(x==a[2][i-1]+a[1][i]){
						ans -= c1[1];
						ans += a[2][i-1];
						ans += m;
						sort(c2+1, c2+1+o);
						c2[1] = c1[1];
						c1[1] = m;
						}
						
					else if(x==a[3][i-1]+a[1][i]){
						ans -= c1[1];
						ans += a[3][i-1];
						ans += m;
						sort(c3+1, c3+1+o);
						c3[1] = c1[1];
						c1[1] = m;
						}
					}
				}
				
			
			else if(m == a[2][i]){
				sort(c2+1, c2+o+1);
	//			c22 = 1;
				if(m > c2[1]){
					ans -= c2[1];
					ans += m;
					c2[1] = m;
//					c22++;
				}
				else{
					int x = 0;
					x = max(a[1][i-1]+a[2][i], a[3][i-1]+a[2][i]);
					x = max(a[2][i-1]+a[1][i], x);
					x = max(x, a[2][i-1]+a[3][i]);
					if(x==a[1][i-1]+a[2][i]){
						ans -= c2[1];
						ans += m;
						ans += a[1][i-1];
						sort(c1+1, c1+1+o);
						c1[1] = c2[1];
						c2[1] = m;
						}
					else if(x==a[3][i-1]+a[2][i]){
						ans -= c2[i];
						ans += m;
						ans += a[3][i-1];
						sort(c3+1, c3+1+o);
						c3[1]= c2[1];
						c2[1] = m;
						}
					
					else if(x==a[2][i-1]+a[1][i]){
						sort(c1+1, c1+o+1);
					//c11 = 1;
					
					if(m > c1[1]){
					ans -= c1[1];
					ans += m;
					c1[1] = m;
					//c11++;
					}
						}
						
					else if(x==a[2][i-1]+a[3][i]){
						sort(c3+1, c3+o+1);
					//c33 = 1;
				//}
				if(m > c3[1]){
					ans -= c3[1];
					ans += m;
					c3[1] = m;
					//c33++;
				}
						}
					}
			}
			
			else{
				//if(c33 == o+1){
					sort(c3+1, c3+o+1);
					//c33 = 1;
				//}
				if(m > c3[1]){
					ans -= c3[1];
					ans += m;
					c3[1] = m;
					//c33++;
				}
				else{
					int x = 0;
					x = max(a[1][i-1]+a[3][i], a[2][i-1]+a[3][i]);
					x = max(a[3][i-1]+a[1][i], x);
					x = max(x, a[3][i-1]+a[1][i]);
					if(x==a[1][i-1]+a[3][i]){
							ans-=c3[1];
							ans+=m;
							ans+=a[1][i-1];
							sort(c1+1, c1+1+o);
							c1[1] = c3[1];
							c3[1] = m;
						}
					else if(x==a[2][i-1]+a[3][i]){
						ans -= c3[i];
						ans+=m;
						ans+=a[2][i-1];
						sort(c2+1, c2+1+o);
						c2[1]= c3[1];
						c3[1] = m;
					}
					
					else if(x==a[3][i-1]+a[1][i]){
							sort(c1+1, c1+o+1);
					//c11 = 1;
					
						if(m > c1[1]){
						ans -= c1[1];
						ans += m;
						c1[1] = m;
					//c11++;
							}
						}
						
					else if(x==a[3][i-1]+a[2][i]){
						sort(c2+1, c2+o+1);
	//			c22 = 1;
					if(m > c2[1]){
						ans -= c2[1];
						ans += m;
						c2[1] = m;
//					c22++;
							}
						}
					}	
				
			}
		}
		cout << ans << endl;
		ans = 0;}
		

		
	return 0;}
	
