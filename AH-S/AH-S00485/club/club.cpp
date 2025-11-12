#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
using namespace std;
//~ #define int long long
typedef long long LL;
const int M=100010;
int t[4],n,T;
int p[4][M];
int a[M][4];
inline int read(){
	int ans=0,f=1;
	char c=getchar_unlocked();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>=48&&c<=57){
		ans=ans*10+c-48;
		c=getchar_unlocked();
	}
	return ans*f;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		int d=0;
		t[1]=t[2]=t[3]=0;
		LL ans=0;
		For(i,1,n){
			a[i][1]=read();a[i][2]=read();a[i][3]=read();
			int mi=1e9,ma=0,x,y;
			For(j,1,3){
				if(a[i][j]<mi) {x=j;mi=a[i][j];}
				if(a[i][j]>ma){y=j;ma=a[i][j];}
			}
			ans=ans+a[i][y];
			p[y][++t[y]]=a[i][y]-a[i][6-x-y];
			if(t[y]>n/2) d=y;
		}
		if(d){
			sort(p[d]+1,p[d]+1+t[d]);
			For(i,1,t[d]-n/2){ans=ans-p[d][i];}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
