//GZ-S00286 贵阳市第一中学 欧阳李樾 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N],b[N],c[N];
int dp(int s,int k,int x,int y,int z){
	if(n<k) return s;
	if(x==n/2) return max(dp(s+c[k],k+1,x,y,z+1),dp(s+b[k],k+1,x,y+1,z));
	if(y==n/2) return max(dp(s+a[k],k+1,x+1,y,z),dp(s+c[k],k+1,x,y,z+1));
	if(z==n/2) return max(dp(s+a[k],k+1,x+1,y,z),dp(s+b[k],k+1,x,y+1,z));
	return max(max(dp(s+a[k],k+1,x+1,y,z),dp(s+b[k],k+1,x,y+1,z)),dp(s+c[k],k+1,x,y,z+1));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		cout<<dp(0,1,0,0,0)<<endl;
	}
	return 0;
}
