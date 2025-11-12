#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
bool cmp(int A,int B){
	return A>B;
}
int main () {
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++)cin>>a[i];
   int x=a[1],y=0;
   sort(a+1,a+1+n*m,cmp);
   for(int i=1;i<=n*m;i++){
       if(a[i]==x){
		   y=i;
		   break;
	   }
   }
   int z=ceil(y*1.0/n);
   cout<<z<<" ";
   if(z%2==1){
	   if(y%n==0)cout<<n;
	   else cout<<y%n;
   }else{
	   if(y%n==0)cout<<1;
	   else cout<<m+1-y%n;
   }
   return 0;
}
