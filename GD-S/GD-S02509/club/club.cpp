#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
int T,n,b[4],c[4],ft,s,l;
struct node{
	int x,y,z;
	bool operator<(const node&b)const{
		if(!ft)return max({x,y,z})>max({b.x,b.y,b.z});
		if(ft==3)return abs(x-y)!=abs(b.x-b.y)?abs(x-y)>abs(b.x-b.y):max(x,y)>max(b.x,b.y);
		if(ft==4)return abs(x-z)!=abs(b.x-b.z)?abs(x-z)>abs(b.x-b.z):max(x,z)>max(b.x,b.z);
		if(ft==5)return abs(y-z)!=abs(b.y-b.z)?abs(y-z)>abs(b.y-b.z):max(y,z)>max(b.y,b.z);
	}
}a[100001];
int mx(int x,int y,int z){
	if(max({x,y,z})==x)return x*10+1;
	if(max({x,y,z})==y)return y*10+2;
	return z*10+3;
}
int mn(int x,int y,int z){
	if(min({x,y,z})==x)return x*10+1;
	if(min({x,y,z})==y)return y*10+2;
	return z*10+3;
}
int md(int x,int y,int z){
	if(x+y+z-max({x,y,z})-min({x,y,z})==x)return x*10+1;
	if(x+y+z-max({x,y,z})-min({x,y,z})==y)return y*10+2;
	return z*10+3;
}
signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	T=rd();
	while(T--){
		n=rd(),b[1]=b[2]=b[3]=s=l=0;
		for(int i=1;i<=n;i++)a[i].x=rd(),a[i].y=rd(),a[i].z=rd(),c[mx(a[i].x,a[i].y,a[i].z)%10]++,b[mx(a[i].x,a[i].y,a[i].z)%10]+=4,b[mn(a[i].x,a[i].y,a[i].z)%10]+=1,b[md(a[i].x,a[i].y,a[i].z)%10]+=2;
		if(mx(c[1],c[2],c[3])/10>n/2)ft=6-mn(b[1],b[2],b[3])%10;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			ft=mx(a[i].x,a[i].y,a[i].z)/10;
			if(mx(a[i].x,a[i].y,a[i].z)%10==mx(b[1],b[2],b[3])%10){
				if(l<n/2)s+=ft,l++;
				else s+=md(a[i].x,a[i].y,a[i].z)/10;
			}
			else s+=ft;
		}
		cout<<s<<endl;
	}
	return 0;
}
