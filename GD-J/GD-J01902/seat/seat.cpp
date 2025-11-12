#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,a[105],l=1,r=1,sum=1;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	long long w=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]!=w){
			if(sum%2==1){
				l++;
				if(l>n){
					l--;
					r++;
					sum++; 
				}
			}else{
				l--;
				if(l<1){
					l++;
					r++;
					sum++;
				}
			}
		}
		else{
			printf("%lld %lld",r,l);
		}
	}
	return 0;
}
