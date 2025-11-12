#include<bits/stdc++.h>
using namespace std;

long long A(int n,int m){
	long long j=1;
	for(int i=n;i>n-m;--i)j=j*i%998244353;
	return j;
}

long long C(int n,int m){
	return A(n,m)/A(m,m);
}

long long SC(int n){
	long long j=0;
	for(int i=3;i<=n;++i)/*cout<<i<<" "<<j<<"\n",*/j+=C(n,i);
	return j;
}

bool pd(int m[],int l){
	long long s=0,ma=0;
	for(int i=0;i<l;++i)s+=m[i],ma=max(ma,(long long)(m[i]));
	return s>ma*2;
}

long long xuan(int n[],int m[],int l,int k,int g,int gg){
	long long s=0;
	if(g==0){
		s=pd(m,gg);
		/*if(s){
			for(int i=0;i<gg;++i)printf(" %d",m[i]);
			printf("\n");
		}*/
	}
	else for(int i=k;i<=l-g;++i)m[gg-g]=n[i],s=(s+xuan(n,m,l,i+1,g-1,gg))%998244353;
	return s;
}

long long z(int n,int m[],int k[]){
	long long s=0;
	for(int i=3;i<=n;++i)/*cout<<i<<"\n",*/s+=xuan(m,k,n,0,i,i);
	return s;
}

bool pda1(int n,int m[]){
	bool a1=true;
	for(int i=0;i<n;++i)if(m[i]!=1)a1=false;
	return a1;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,R[5005],m[5005];
	cin>>n;
	for(int i=0;i<n;++i)cin>>R[i];
	cout<<(pda1(n,R)?SC(n):z(n,R,m));
}
