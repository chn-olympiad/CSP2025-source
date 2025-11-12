#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct pp{
	int a,b,c,d,mx,mn;
}h[100005];
bool cmp(pp x,pp y){
	if(x.d!=y.d)return x.d>y.d;
	else return x.mx-x.mn>y.mx-y.mn;
}
int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	F;
	ll t,n,i,j,x,y,z;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;++i){
			cin>>h[i].a>>h[i].b>>h[i].c;
			int mx=max(h[i].a,max(h[i].b,h[i].c)),mn=min(h[i].a,min(h[i].b,h[i].c)),T;
			if(h[i].a!=mx&&h[i].a!=mn)T=h[i].a;
			else if(h[i].b!=mx&&h[i].b!=mn)T=h[i].b;
			else T=h[i].c;
			h[i].d=mx-T,h[i].mx=mx,h[i].mn=mn;
		}
		sort(h,h+n,cmp);
		for(i=j=x=y=z=0;i<n;++i){
			int mx=max(h[i].a,max(h[i].b,h[i].c));
			if(h[i].a==mx&&h[i].b==mx&&h[i].c==mx){
				j+=mx;
				if(x<y&&x<z)++x;
				else if(y<z&&y<x)++y;
				else ++z;
			}else if(h[i].a==mx&&h[i].b==mx){
				if(x<y)++x;
				else ++y;
				j+=mx;
			}else if(h[i].a==mx&&h[i].c==mx){
				if(x<z)++x;
				else ++z;
				j+=mx;
			}else if(h[i].b==mx&&h[i].c==mx){
				if(y<z)++y;
				else ++z;
				j+=mx;
			}
			else if(h[i].a==mx){
				if(2*x<n)x++,j+=h[i].a;
				else{
					if(h[i].b>h[i].c&&y*2<n)++y,j+=h[i].b;
					else ++z,j+=h[i].c;
				}
			}else if(h[i].b==mx){
				if(2*y<n)y++,j+=h[i].b;
				else{
					if(h[i].a>h[i].c&&x*2<n)++x,j+=h[i].a;
					else ++z,j+=h[i].c;
				}
			}else{
				if(2*z<n)z++,j+=h[i].c;
				else{
					if(h[i].a>h[i].b&&x*2<n)++x,j+=h[i].a;
					else ++y,j+=h[i].b;
				}
			}
		}
		cout<<j<<"\n";
	}
	return 0;
}
