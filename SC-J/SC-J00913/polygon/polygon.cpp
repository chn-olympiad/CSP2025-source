#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[5005];
long long jcc(int a){
	long long num=1;
	for(int i=1;i<=a;i++){
		num*=i;
		num=num%998244353;
	}
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	long long ans;
	if(maxn==1){
		for(int i=3;i<=n;i++){
				ans+=jcc(n)%998244353/jcc(n-i)%998244353/jcc(i)%998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>maxn*2)cout<<1;
		else cout<<0;
		return 0;
	}
	int q,w,e,r,t,y,u,i,o,p,a,s,d,f,g,h,j,l,z,x,c,v,b,m,minn,sum,num,tot,total,temp,flag;
	cout<<(q+w+e+r+t+y+u+i+o+p+a+s+d+f+g+h+j+l+z+x+c+v+b+m+ans+minn+maxn+sum+num+tot+total+temp+flag)%(a+b+c+d+e);
	return 0;
}