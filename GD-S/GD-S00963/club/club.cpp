#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[10][100086];
int co[10];
int t,n,o,i,p,b,c,s,io,ip,ii,co1,co2,co3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		for(int j=1;j<=n;j++) for(int k=1;k<=3;k++) a[k][j]=0;
		cin>>n;
		memset(co,0,sizeof(co));
		if(n == 2){
			for(int j=1;j<=n;j++) for(int k=1;k<=3;k++) cin>>a[k][j];
			b = max(a[2][1]+a[3][2],max(a[3][1]+a[1][2],a[3][1]+a[2][2]));
			c = max(a[1][1]+a[3][2],max(a[1][1]+a[2][2],a[2][1]+a[1][2]));
			cout<<max(b,c)<<endl;
		}else{
			for(int j=1;j<=n;j++) for(int k=1;k<=3;k++) cin>>a[k][j];
			s = 0;
			for(int j=1;j<=n;j++){
				o=0,i=0;p=0,co1=co[1],co2=co[2],co3=co[3];
				io=0,ii=0,ip=0;
				for(int k=1;k<=n;k++){
					if (a[1][k]>o) o = a[1][k],io=k;
					if (a[2][k]>i) i = a[2][k],ii=k;
					if (a[3][k]>p) p = a[3][k],ip=k;
				}
				if(o > i){
					if(o > p){
						if(co[1]+1 <= n/2) co[1]++,s+=o;
						else if(i > p and co[2]+1 <= n/2) co[2]++,s+=i;
						else co[3]++,s+=p;
					}else{
						if(co[3]+1 <= n/2) co[3]++,s+=p;
						else if(co[1]+1 <= n/2) co[1]++,s+=o;
						else co[2]++,s+=i;
					}
				}else{
					if(i > p){
						if(co[2]+1 <= n/2) co[2]++,s+=i;
						else if(p > o and co[3]+1 <= n/2) co[3]++,s+=p;
						else co[1]++,s+=o; 
					}else{
						if(co[3]+1 <= n/2) co[3]++,s+=p;
						else if(co[2]+1<=n/2) co[2]++,s+=i;
						else co[1]++,s+=o;
					}
				}
				if(co1 < co[1]) a[1][io] = 0,a[2][io] = 0,a[3][io] = 0;
				else if(co2 < co[2]) a[1][ii] = 0,a[2][ii] = 0,a[3][ii] = 0;
				else a[1][ip] = 0,a[2][ip] = 0,a[3][ip] = 0;
			}
			cout<<s<<endl;
		}
	}
	return 0;
}

