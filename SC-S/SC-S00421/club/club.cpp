#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int zd,z,j,i,t,s,k,a[N],b[N],c[N],d[N][N],n,mx=-1;
bool cmp(int x,int y){
	return x>y;
}
/*void f(int sum,int h,int a1,int b1,int c1){
	if(a1>zd||b1>zd||c1>zd){
			return;
		}
	if(h>=n){
		mx=max(mx,sum);
		return;
	}
	f(sum+a[h],h++,a1++,b1,c1);
	f(sum+b[h],h++,a1,b1++,c1);
	f(sum+c[h],h++,a1,b1,c1++);
	
}*/
int fs(){
	cin>>n;
	zd=n/2;
	for(i=1;i<=n;i++){
		cin>>d[1][i]>>d[2][i]>>d[3][i];
	}
	for(i=1;i<=n;i++){
		d[1][i]+=max(d[1][i-1],max(d[2][i-1],d[3][i-1]));
		d[2][i]+=max(d[1][i-1],max(d[2][i-1],d[3][i-1]));
		d[3][i]+=max(d[1][i-1],max(d[2][i-1],d[3][i-1]));
	}
	//f(0,0,0,0,0);
	mx=max(d[1][n-1],max(d[2][n-1],d[3][n-1]));
	cout<<mx<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for( k=1;k<=t;k++){
		fs();
	}
	return 0;
}