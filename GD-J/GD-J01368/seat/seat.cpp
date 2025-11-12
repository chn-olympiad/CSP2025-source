#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct stu {
	long long x,y;
	long long a,b;
}f[1005];
bool cmp(stu fa,stu fb) {
	return fa.x>fb.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>f[i].x,f[i].y=i;
	sort(f+1,f+n*m+1,cmp);
	for(int i=1;i<=m;i++) {
		if(i%2) 
			for(int j=1;j<=n;j++) f[++k].a=i,f[k].b=j;
		else
			for(int j=n;j>=1;j--) f[++k].a=i,f[k].b=j;
	}
	for(int i=1;i<=n*m;i++)
		if(f[i].y==1){
			cout<<f[i].a<<' '<<f[i].b;
			return 0;
		}
	return 0;
}

