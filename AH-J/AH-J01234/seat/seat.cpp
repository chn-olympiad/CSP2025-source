#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[110],n,m;
bool cmp(LL a,LL b){
	return a>b;
}
void calc(LL ans){
	LL c=ans/n;c+=(ans%n>0);
	ans%=n;
	LL r;
	if(c%2==1)
		if(ans!=0) r=ans;
		else r=n;
	else
		if(ans!=0) r=n-ans+1;
		else r=1;
	cout<<c<<" "<<r<<endl;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++) cin>>a[i];
	LL a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	LL ans;
	for(LL i=1;i<=n*m;i++)
		if(a[i]==a1){
			ans=i;
			break;
		}
	calc(ans);
	return 0;
}
