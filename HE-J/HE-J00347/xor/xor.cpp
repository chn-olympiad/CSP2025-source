#include <bits/stdc++.h>
using namespace std;
long long a[1000000],n,k;
int l[1000000],r[1000000],p=0;
int xors(int a,int b){
	long long s=0;
	int a1[100],b1[100],pa=0,pb=0;
	for(int i=0;i<100;++i){
		a1[i]=0;
		b1[i]=0;
	}
	while(a>=1){
		a1[pa]=a%2;
		pa++;
		a/=2;
	}
	while(b>=1){
		b1[pb]=b%2;
		pb++;
		b/=2;
	}
	for(int i=max(pa,pb)-1;i>=0;--i){
		if(a1[i]!=b1[i])
			s+=pow(2,i);
	}
	return s;
}
int xorsum(int l,int r){
	long long s=a[l];
	if(l==r)
		return a[l];
	for(int i=l+1;i<=r;++i)
		s=xors(s,a[i]);
	return s;
}
bool comp(int a,int b){
	if(l[a]>r[b]||l[b]>r[a])
		return 1;
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<n;++i){
		for(int q=i;q<n;++q){
			if(xorsum(i,q)==k){
				l[p]=i;
				r[p]=q;
				p++;
			}
		}
	}
	int m=0;
	for(int i=0;i<p;++i){
		int u=i,s=1;
		for(int q=i+1;q<p;++q){
			if(comp(u,q)){
				u=q;
				s++;
			}
		}
		m=max(m,s);
	}
	cout<<m;
	return 0;
}
