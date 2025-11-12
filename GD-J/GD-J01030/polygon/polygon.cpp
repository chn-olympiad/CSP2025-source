#include<bits/stdc++.h>
#define lli long long
using namespace std;
const int N=5005;
int n,a[N],z;
lli wn;
bool check(lli x){
	int s=0,sm=0,mx=0,i=1;
	for(lli wi=1;wi<=x;wi<<=1){
		if(x&wi){
			s++;sm+=a[i];
			mx=max(mx,a[i]);
		}i++;
	}return (s>=3)&&(sm>mx*2);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);wn=1ll<<n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(lli i=7;i<wn;i++){
		if(check(i))++z,z%=998244353;
	}
	printf("%d",z);
	return 0;
}
