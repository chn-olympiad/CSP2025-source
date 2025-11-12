#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
#define maxn 100
using namespace std;
LL n,sum,Sum;
LL a[maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	if(n<3){
		printf("0");
		return 0;
	}
	if(n==3){
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		if(a[n]*2>=sum) sum-=a[n--];
		else break;
	return 0;
}
