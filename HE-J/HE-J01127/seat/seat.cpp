#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'//交互题注释
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
inline ll read(){
	ll x=0,t=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')t=-t;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return t*x;
}
int n,m;
int a[105],l,wz;
int r,c;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	file("seat");
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	l=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==l)wz=i;
	c=(wz+n-1)/n;
	if(c&1){
		r=(wz-1)%n+1;
	}else{
		r=n-((wz-1)%n+1)+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
//c列r行
//m列n行 
//n=4,m=5,wz=5,c=2,r=4;
/*
3 3
100 95 94
 99 96 93 
 98 97 92
*/
