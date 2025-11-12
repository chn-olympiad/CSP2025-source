#include<bits/stdc++.h>
using namespace std;

const int N=105;
int a[N];

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}

inline bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) a[i]=read();
	int now=a[1],idx;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==now) idx=i;
	int nx=0,ny=1;
	for(int i=1;i<=n*m;i++){
		if(ny%2==1) nx++;
		else nx--; 
		if((ny%2==1) && nx==n+1) ny++,nx=n;
		if((ny%2==0) && nx==0) ny++,nx=1;
		if(i==idx){
			cout<<ny<<" "<<nx;
			break;
		}
	}
	return 0;
}