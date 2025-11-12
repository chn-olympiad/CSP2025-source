#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,f,n) for(long long i=f;i<=n;i++) 
#define dlp(i,a,b) for(long long i=a;i>=b;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
#define st first
#define ed second
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int MAXN=5e5+5;
int n,k,a[MAXN],p[22][MAXN];
bool kt[22]={false};
vector<pair<int,int>> q;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	bool flag=false;
	int b1=0,b0=0;
	ulp(i,1,n){
		a[i]=read();
		if(a[i]==1)++b1;
		if(a[i]==0)++b0;
	}
	if(k==1){
		write(b1);
		return 0;
	}
	else if(k==0&&b1+b0==n){//
		int ans=b0;
		ulp(i,1,n){
			if(a[i]!=0&&a[i-1]!=0){
				ans++;
				a[i]=a[i-1]=0;
			}
		}
		write(ans);
		return 0;
	}
	ulp(i,0,20)
		kt[i]=(k>>i)&1;
	ulp(i,1,n){
		ulp(j,0,20){
			p[j][i]=p[j][i-1]+((a[i]>>j)&1);
		}
	}
	ulp(i,1,n){
		ulp(j,i,n){
			bool flag=true;
			ulp(bbd,0,20){
				if((p[bbd][j]-p[bbd][i-1])&1!=kt[bbd]){
					flag=false;
					break;
				}
			}
			if(flag){
				q.pb({i,j});
			}
		}
	}
	int ans=0;
	int txt=0; 
	ulp(i,0,q.size()-1){
		if(i!=0&&q[i].st<=q[txt].ed){
			continue;
		}
		ans++;
		txt=i;
	}
	write(ans);
}
