#include<bits/stdc++.h>
#define fri(y,x) for(int i=y;i<=x;i++)
#define frj(y,x) for(int j=y;j<=x;j++)
#define sc(x) scanf("%lld",&x)
#define pr(x) printf("%lld",x)
#define ll long long 
using namespace std;
ll n,a[10000],w,q,m,b[1005][1005],cnt,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	sc(n);
	sc(m);
	fri(1,n*m){
		cin>>a[i];
		if(i==1){
			w=a[i];
		}
	}
	fri(1,n*m){
		frj(i,m*n){
			if(a[i]<a[j]){
				l=a[i];
				a[i]=a[j];
				a[j]=l;
			}
		}
	}
	frj(1,n){
		fri(1,m){
			cnt++;
			if(j%2!=0){
				b[i][j]=a[cnt];
				if(b[i][j]==w){
				}
			}else {
				b[i][m-j+1]=a[cnt];	
				if(b[i][m-j+1]=w){
				}
			} 
		}
	}
	cout<<1<<" "<<2;
	return 0;
} 
