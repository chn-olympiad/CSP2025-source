#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool cmp(const LL x,const LL y){return x>y;}
LL n,m,a[105],y,x,len;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++) cin>>a[i];
	LL x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			len=i;
			break;
		}
	}
	if(len%n!=0) y=len/n+1;
	else y=len/n;
	if(y%2==1){
		if(len%n==0) x=n;
		else x=len%n;
	}
	else x=n-(len%n)+1;
	cout<<y<<" "<<x;
	return 0;
}
