#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],t,lb=0,s[100005],ts[100005];
struct B{
	long long l,r,z;
}b[100005];
bool cmp(B a,B b){
	return a.l<b.l;
}
long long lxor(long long i,long long j){
	long long t=a[i++];
	for(;i<=j;++i){
		t=t^a[i];
	}
	return t;
}
long long listmax(){
	long long maxl=s[0];
	for(int i=1;i<lb;++i){
		maxl=max(maxl,s[i]);
	}
	return maxl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	scanf("%lld %lld",&n,&k);
	for(long long i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}
	for(long long i=0;i<n;++i){
		for(long long j=i;j<n;++j){
			t=lxor(i,j);
			if(t==k){
				b[lb].l=i;
				b[lb].r=j;
				b[lb++].z=j-i;
			}	
		}
	}
	sort(b,b+lb,cmp);
	s[0]=1;
	for(long long i=1;i<lb;++i){
		long long maxl=0;
		for(long long j=0;j<i;++j){
			if(b[j].r<b[i].l)	maxl=max(maxl,s[j]);
		}
		s[i]=maxl+1;
	}
	printf("%lld",listmax());
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
