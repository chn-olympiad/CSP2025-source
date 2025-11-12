#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
LL n,a[N][4],f[N],k,t,cnt,s,d;
bool cmp(LL a,LL b){
	return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		cnt=0;
		cin>>n;
		k=n/2;
		if(n==2){
		 for(int i=1;i<=n;i++){
		  for(int j=1;j<=3;j++)
			cin>>a[i][j];
		 }
		  LL p=a[1][1]+a[2][2];
		  LL q=a[1][1]+a[2][3];
		  LL l=a[1][2]+a[2][1];
		  LL r=a[1][2]+a[2][3];
		  LL u=a[1][3]+a[2][1];
		  LL v=a[1][3]+a[2][2];
		  LL w1=max(p,q),w2=max(l,r),w3=max(u,v);
		  cout<<max(max(w1,w2),w3);
	    } 
	    else{
		   for(int i=1;i<=n;i++){
			cin>>f[i]>>s>>d;
		 }
		  sort(f+1,f+n+1,cmp); 
		  for(int i=1;i<=k;i++){
			  cnt+=f[i];
		}
		  cout<<cnt;
	    }
	}
    return 0;
}
