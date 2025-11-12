#include<bits/stdc++.h>

#define hyc_qcz_jmr_baoyouwo_AC
#define zty_AK_CSPJ_2025

#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fep(i,s,e) for(int i=s;i<e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
#define pef(i,s,e) for(int i=s;i>e;i--)

namespace FastIO{
	template <typename T> inline void read(T &x){
		x=0;
		T f=1;
		T c=getchar();
		for(;!isdigit(c);c=getchar()){
			if(c=='-'){
				f=-1;
			}
		}
		for(;isdigit(c);c=getchar()){
			x=(x<<1)+(x<<3)+(c^48);
		}
		x*=f;
	}
	template <typename T> inline void print(T x){
		if(x<0){
			putchar('-');
			x=-x;
		}
		if(x>9){
			print(x/10);
		}
		putchar((x%10)^48);
	}
}

using namespace std;
using namespace FastIO;
int n,m,a[105],num,x,y; 
int main(){
	hyc_qcz_jmr_baoyouwo_AC
	zty_AK_CSPJ_2025
//	freopen("seat4.in","r",stdin);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n);
	read(m);
	rep(i,1,n*m){
		read(a[i]);
		if(a[i]>a[1]){
			num++;
		}
	}
	x=num/n+1;
	if(x%2==1){
		y=num%n+1;
	}
	else{
		y=n-num%n;
	}
	print(x);
	putchar(' ');
	print(y);
	return 0;
}