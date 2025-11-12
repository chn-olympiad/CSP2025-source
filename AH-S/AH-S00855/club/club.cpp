#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,zd,zdz,cdz,zx,cd;
};
node a[100005];
bool cmp(node xx,node yy){
	if(min(min(xx.x,xx.y),xx.z)>yy.zdz&&xx.zx!=yy.zd){
		return 0;
	}
	if(min(min(yy.x,yy.y),yy.z)>xx.zdz&&xx.zd!=yy.zx){
		return 1;
	}
	if(xx.cdz>yy.zdz&&xx.cd!=yy.zd){
		return 0;
	}
	if(yy.cdz>xx.zdz&&yy.cd!=xx.zd){
		return 1;
	}
	return xx.zdz>yy.zdz;
}
bool cmpa(node x,node y){
	return x.x>y.x;
}
bool cmpb(node x,node y){
	if(x.cdz>y.zdz&&x.cd!=y.zd){
		return 0;
	}
	if(y.cdz>x.zdz&&y.cd!=x.zd){
		return 1;
	}
	return x.zdz>y.zdz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;cin >> t;
	while(t--){
		int flag = 1,flag2 = 1;
		int n;
		cin >> n;
		for(int i = 1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y!=0||a[i].z!=0){
				flag = 0;
			}
			if(a[i].z!=0){
				flag2 = 0;
			}
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				a[i].zd = 1;
				a[i].zdz = a[i].x;
			}
			else if(a[i].y>a[i].x&&a[i].y>a[i].z){
				a[i].zd = 2;
				a[i].zdz = a[i].y;
			}
			else{
				a[i].zd = 3;
				a[i].zdz = a[i].z;
			}
			if(a[i].x>a[i].y&&a[i].x<a[i].z){
				a[i].cd = 1;
				a[i].cdz = a[i].x;
			}
			else if(a[i].y>a[i].x&&a[i].y<a[i].z){
				a[i].cd = 2;
				a[i].cdz = a[i].y;
			}
			else{
				a[i].cd = 3;
				a[i].cdz = a[i].z;
			}
			if(a[i].x<a[i].y&&a[i].x<a[i].z){
				a[i].zx = 1;
			}
			else if(a[i].y<a[i].x&&a[i].y<a[i].z){
				a[i].zx = 2;
			}
			else{
				a[i].zx = 3;
			}	
		}
		if(flag == 1){
			long long ans = 0;
			sort(a+1,a+n+1,cmpa);
			for(int i = 1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout << ans<<endl;
		}
		else if(flag2 == 1){
			sort(a+1,a+n+1,cmpb);
			long long ans = 0;
			int sum1=0,sum2=0;
			for(int i = 1;i<=n;i++){
				if(a[i].zd == 1){
					if(sum1+1>n/2){
						sum2++;
						ans+=a[i].y;
					}
					else{
						sum1++;
						ans+=a[i].x;
					}
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				a[i].zd = 1;
				a[i].zdz = a[i].x;
			}
			else if(a[i].y>a[i].x&&a[i].y>a[i].z){
				a[i].zd = 2;
				a[i].zdz = a[i].y;
			}
				}
				else{
					if(sum2+1>n/2){
						sum1++;
						ans+=a[i].x;
					}
					else{
						sum2++;
						ans+=a[i].y;
					}
				}
			}
			cout << ans << endl;
		}
		else{
			sort(a+1,a+n+1,cmp);
			int sum1 = 0,sum2 = 0,sum3 = 0;
			long long ans = 0;
			for(int i = 1;i<=n;i++){
				if(a[i].zd == 1){
					if(sum1+1>n/2){
						if(a[i].y>a[i].z){
							if(sum2+1>n/2){
								sum3++;
								ans+=a[i].z;
							}
							else{
								sum2++;
								ans+=a[i].y;
							}
						}
						else if(a[i].z>a[i].y){
							if(sum3+1>n/2){
								sum2++;
								ans+=a[i].y;
							}
							else{
								sum3++;
								ans+=a[i].z;
							}
						}
					else{
						if(sum2<sum3){
							sum2++;
							ans+=a[i].y;
						}
						else{
							sum3++;
							ans+=a[i].z;
						}
					}
				}
				else{
					sum1++;
					ans+=a[i].x;
				}
			}
			else if(a[i].zd == 2){
				if(sum2+1>n/2){
					if(a[i].x>a[i].z){
						if(sum1+1>n/2){
							sum3++;
							ans+=a[i].z;
						}
						else{
							sum1++;
							ans+=a[i].x;
						}
					}
					else if(a[i].z>a[i].x){
						if(sum3+1>n/2){
							sum1++;
							ans+=a[i].x;
						}
						else{
							sum3++;
							ans+=a[i].z;
						}
					}
					else{
						if(sum1<sum3){
							sum1++;
							ans+=a[i].x;
						}
						else{
							sum3++;
							ans+=a[i].z;
						}
					}
				}
				else{
					sum2++;
					ans+=a[i].y;
				}
			}
			else if(a[i].zd == 3){
				if(sum3+1>n/2){
					if(a[i].y>a[i].x){
						if(sum2+1>n/2){
							sum1++;
							ans+=a[i].x;
						}
						else{
							sum2++;
							ans+=a[i].y;
						}
					}
					else if(a[i].x>a[i].y){
						if(sum1+1>n/2){
							sum2++;
							ans+=a[i].y;
						}
						else{
							sum1++;
							ans+=a[i].x;
						}
					}
					else{
						if(sum2<sum1){
							sum2++;
							ans+=a[i].y;
						}
						else{
							sum1++;
							ans+=a[i].x;
						}
					}
				}
				else{
					sum3++;
					ans+=a[i].z;
				}
			}
		}
		cout << ans << endl;
		}
	}
	return 0;
}
