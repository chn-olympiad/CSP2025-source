#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=110;
int n,m,l,h,p,lop,k;
struct syx{
	int w;
}a[N];
bool cmp(syx x,syx y){
	return x.w>y.w;
}
signed main(){
     freopen("seat.in","r",stdin);
     freopen("seat.out","w",stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     cin>>n>>m;
     p=n*m;
     for(int i=1;i<=p;i++){
		 cin>>a[i].w;
	 }
	 k=a[1].w;
	 sort(a+1,a+1+p,cmp);
	 for(int i=1;i<=p;i++){
		 if(a[i].w==k){
			 lop=i;
			 break;
		 }
	 }
	 l=(lop+(n-1))/n;
	 if(l%2==0){
		 h=n+1-(lop%n);
		 if(h==n+1)h=1;
	 }else{
		 h=lop%n;
		 if(h==0)h=n;
	 }
	 cout<<l<<" "<<h;
     return 0;
}
