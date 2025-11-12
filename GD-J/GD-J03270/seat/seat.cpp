#include<bits/stdc++.h>
using namespace std;
int n,m,tmp,k,a[1000010],l,r,mid,ans;
bool cmp(const int&x,const int&y){
	return x>y;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	l=1,r=n*m;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]>=tmp){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	if(ans%n==0)cout<<ans/n<<" ",k=ans/n;
	else cout<<ans/n+1<<" ",k=ans/n+1;
	if(k%2==1){
		if(ans%n==0)cout<<n;
		else cout<<(ans%n);
	}else{
		if(ans%n==0)cout<<1;
		else cout<<n-(ans%n)+1;
	}
	return 0;
} //#Shang4Shan3Ruo6Shui4
/*
3 3
94 95 96 97 98 99 100 93 92
*/
