#include<bits/stdc++.h>
using namespace std;
int yh(int x,int y){
	int z=0,a=1;
	while(x>0||y>0){
		int xx=x%2,yy=y%2;
		if(xx!=yy){
			z+=a;
		}
		a*=2;
		x/=2;
		y/=2;
	}
	return z;
}
int hy(int x,int y){
	int z=0,a=1;
	while(x>0||y>0){
		int xx=x%2,yy=y%2;
		if(xx==0){
			if(yy==1){
				z+=a;
			}
		}else{
			if(yy==0){
				z+=a;
			}
		}
		a*=2;
		x/=2;
		y/=2;
	}
	return z;
}
int a[500005],n,k,b[500005];
map<int,int>m[500005];
map<int,int>p;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		if(i==1){
			a[i]=s;
		}else{
			a[i]=yh(a[i-1],s);
		}
		p[a[i]]++;
		m[a[i]][p[a[i]]]=i;
		
	}
	for(int i=1;i<=n;i++){
		int y=yh(k,a[i-1]);
		int z=p[y]/2,a=p[y]/2;
		while(a){
			if(m[y][z]>i){
				z-=(a/2);
			}else{
				z+=(a/2);
			}
			a/=2;
		}
		if(m[y][z]<i){
			z++;
		}
		if(m[y][z]<i){
			b[i]=-1;
		}else{
			b[i]=m[y][z];
		}
		//cout<<b[i]<<' ';
	}
	int i=1,t=0;
	while(i<=n){
		int f=i,mn=1e9;
		while(i<=n&&i-f<mn){
			if(b[i]==-1){
				i++;
			}else{
				mn=min(mn,i-f+b[i]);
				i++;
			}
		}
		if(mn!=1e9){
			t++;
		}
	}
	cout<<t;
	return 0;
}
