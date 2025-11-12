#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100100;
struct kk{
	int f;
	int s;
	int t;
}a[N];
int cmp(kk x,kk y){
	if(x.f==y.f){
		if(x.s==y.s){
			return x.t>y.t;
		}
		else{
			return x.s>y.s;
		}
	}
	else{
		return x.f>y.f;
	}
} 
int T,n,b[N][5],c[N];
int ans,sum1,sum2,sum3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			b[i][1]=1;
			b[i][2]=2;
			b[i][3]=3;
		}
		for(int i=1;i<=n;i++){
			if(a[i].f<a[i].s){
				swap(a[i].f,a[i].s);
				swap(b[i][1],b[i][2]);
			}
			if(a[i].f<a[i].t){
				swap(a[i].f,a[i].t);
				swap(b[i][1],b[i][3]);
			}
			if(a[i].s<a[i].t){
				swap(a[i].s,a[i].t);
				swap(b[i][2],b[i][3]);
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i][1]==1){
				sum1++;
			}
			else if(b[i][1]==2){
				sum2++;
			}
			else if(b[i][1]==3){
				sum3++;
			}
		}
			if(sum1<=n/2&&sum2<=n/2&&sum3<=n/2){
				for(int i=1;i<=n;i++){
					ans+=a[i].f;
				}
			}
			else if(sum2>n/2){
				int cot=0;
				for(int i=1;i<=n;i++){
					if(b[i][1]==2){
						ans+=a[i].f;
						cot++;
					}
					if(cot==n/2){
						break;
					}
				}
				for(int i=1;i<=n;i++){
					if(b[i][1]!=2){
						ans+=a[i].f;
					}
					if(b[i][1]==1){
						ans+=a[i].s;
					}
				}
			}
			else if(sum1>n/2){
				int cot=0;
				for(int i=1;i<=n;i++){
					if(b[i][1]==1){
						ans+=a[i].f;
						cot++;
					}
					if(cot==n/2){
						break;
					}
				}
				for(int i=1;i<=n;i++){
					if(b[i][1]!=1){
						ans+=a[i].f;
					}
				}
			}
			else if(sum3>n/2){
				int cot=0;
				for(int i=1;i<=n;i++){
					if(b[i][1]==3){
						ans+=a[i].f;
						cot++;
					}
					if(cot==n/2){
						break;
					}
				}
				for(int i=1;i<=n;i++){
					if(b[i][1]!=3){
						ans+=a[i].f;
					}
				}
			}
			cout<<ans<<endl;
			sum1=0;
			sum2=0;
			sum3=0;
			ans=0;
		}
	return 0;
} 
/*
2
2
0 0 4
8 9 10

2
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
