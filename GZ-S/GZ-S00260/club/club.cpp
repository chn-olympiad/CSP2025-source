//GZ-S00260 贵阳市花溪区英语实验学校 杨尚卿 
#include<bits/stdc++.h>
using namespace std;
int t,n,m1,m2,m3,cnt1=0,cnt2=0,t1,t2,t3,cnt=0;
struct dj{
	int m1,m2,m3;
}a[10005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	 cin>>t;
	 while(t--){
	 	cin>>n;
	 	cnt1=0,cnt2=0,cnt=0,m1=0,m2=0,m3=0,t1=0,t2=0,t3=0;
	 	for(int i=1;i<=n;i++){
	 		cin>>a[i].m1>>a[i].m2>>a[i].m3;
		 }
		for(int i=1;i<=n;i++){
			if(a[i].m1>=a[i].m2&&a[i].m1>=a[i].m3&&m1<=n/2-1){
				m1++;
				cnt1+=a[i].m1;
			}else if(m1>n/2-1&&a[i].m1>=a[i].m2&&a[i].m1>=a[i].m3){
				if(a[i].m1>=a[i].m2&&a[i].m2>=a[i].m3&&m2<=n/2-1){
					m2++;
					cnt1+=a[i].m2;
				}else if(a[i].m1>=a[i].m3&&a[i].m3>=a[i].m2&&m3<=n/2-1){
							m3++;
							cnt1+=a[i].m3;
						}
			}
			if(a[i].m2>=a[i].m1&&a[i].m2>a[i].m3&&m2<=n/2-1){
				m2++;
				cnt1+=a[i].m2;
			}else if(m2>n/2-1&&a[i].m2>=a[i].m1&&a[i].m2>=a[i].m3){
				if(a[i].m2>=a[i].m1&&a[i].m1>=a[i].m3&&m1<=n/2-1){
					m1++;
					cnt1+=a[i].m1;
				}else if(a[i].m2>=a[i].m3&&a[i].m3>=a[i].m1&&m3<=n/2-1){
							m3++;
							cnt1+=a[i].m3;
						}
			}
			if(a[i].m3>a[i].m1&&a[i].m3>a[i].m2&&m3<=n/2-1){
				m3++;
				cnt1+=a[i].m3;
			}else if(m3>n/2-1&&a[i].m3>=a[i].m1&&a[i].m3>=a[i].m2){
				if(a[i].m1>=a[i].m2&&a[i].m3>=a[i].m1&&m1<=n/2-1){
					m1++;
					cnt1+=a[i].m1;
				}else if(a[i].m3>=a[i].m2&&a[i].m2>=a[i].m1&&m2<=n/2-1){
							m2++;
							cnt1+=a[i].m2;
						}
			}
//			cout<<"s "<<m1<<" "<<m2<<" "<<m3<<" "<<cnt1<<'\n';
		}
		for(int i=n;i>=1;i--){
			if(a[i].m1>=a[i].m2&&a[i].m1>=a[i].m3&&t1<=n/2-1){
				t1++;
				cnt2+=a[i].m1;
			}else if(t1>n/2-1&&a[i].m1>=a[i].m2&&a[i].m1>=a[i].m3){
				if(a[i].m1>=a[i].m2&&a[i].m2>=a[i].m3&&t2<=n/2-1){
					t2++;
					cnt2+=a[i].m2;
				}else if(a[i].m1>=a[i].m3&&a[i].m3>=a[i].m2&&t3<=n/2-1){
							t3++;
							cnt2+=a[i].m3;
						}
			}
			if(a[i].m2>=a[i].m1&&a[i].m2>a[i].m3&&t2<=n/2-1){
				t2++;
				cnt2+=a[i].m2;
			}else if(t2>n/2-1&&a[i].m2>=a[i].m1&&a[i].m2>=a[i].m3){
				if(a[i].m2>=a[i].m1&&a[i].m1>=a[i].m3&&t1<=n/2-1){
					t1++;
					cnt2+=a[i].m1;
				}else if(a[i].m2>=a[i].m3&&a[i].m3>=a[i].m1&&t3<=n/2-1){
							t3++;
							cnt2+=a[i].m3;
						}
			}
			if(a[i].m3>a[i].m1&&a[i].m3>a[i].m2&&t3<=n/2-1){
				t3++;
				cnt2+=a[i].m3;
			}else if(t3>n/2-1&&a[i].m3>=a[i].m1&&a[i].m3>=a[i].m2){
				if(a[i].m3>=a[i].m1&&a[i].m1>=a[i].m2&&t1<=n/2-1){
					t1++;
					cnt2+=a[i].m1;
				}else if(a[i].m3>=a[i].m2&&a[i].m2>=a[i].m1&&t2<=n/2-1){
							t2++;
							cnt2+=a[i].m2;
						}
			}
//			cout<<"x "<<t1<<" "<<t2<<" "<<t3<<" "<<cnt2<<'\n';
		}
		cnt=max(cnt1,cnt2);
		cout<<cnt<<'\n';
	 }
	return 0;
}

