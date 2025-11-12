#include<bits/stdc++.h>
using namespace std;
#define int long long
bool f,ff;
int tot,tot1,tot2,n,m,a[102],p;
struct w{
	int x,y;
}b[102];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tot=a[1];
	b[0].x=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		b[a[i]].x=b[a[i-1]].x;
		if(f) b[a[i]].y=b[a[i-1]].y-1;
		else b[a[i]].y=b[a[i-1]].y+1;
		if(ff) b[a[i]].y--;
		ff=0;
		if(b[a[i-1]].y==m&&!f){
			b[a[i]].x++;
			b[a[i]].y--;
			f=1;
			ff=0;
		}
		else if(f){
			if(b[a[i]].y==1){
				f=0;
				ff=1;
				b[a[i]].x++;
			}
		}
	}
	cout<<b[tot].x<<" "<<b[tot].y;
}
