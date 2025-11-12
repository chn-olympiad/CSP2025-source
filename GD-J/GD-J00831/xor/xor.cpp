#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,x,y,a[N],c[10010][10010],d[N],ma=0,j,l,k,i,o,p,t,h,g,f,r,e,w,q,z;
string s,s1,s2;
struct No{
	long long l,r;
}b[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;	
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(j==i)c[i][j]=a[j];
			else c[i][j]^=a[j];
			if(c[i][j]==m){
				x++;
				b[x].l=i;
				b[x].r=j;
			}
		}
	}
	while(x!=y){
		y++;
		if(b[y].l>r){
			t++;
			r=b[y].r;
		}
		if(t>ma)ma=t;
	}
	cout<<ma;
	return 0;
}
