#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,a[105],s,wz;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1; ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0',ch=getchar();}
	return x*f;
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read(),s=read();
	for(int i=1;i<n*m;i++)
		a[i]=read();
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<n*m;i++)
		if(a[i]<s){
			wz=i;
			break;
		}
	ll ls=wz/n,hs=wz%n;
	if(hs){
		ls++;
		if(ls%2==1) cout<<ls<<" "<<hs;
		else        cout<<ls<<" "<<n-hs+1;
	}
	else{
		if(ls%2==1) cout<<ls<<" "<<n;
		else        cout<<ls<<" "<<1;
	}
	return 0;
}