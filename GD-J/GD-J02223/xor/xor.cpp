#include<bits/stdc++.h>
using namespace std;
int d[2003][2003],n,a[500005],k1;
int dp(int i,int j){
	if(d[i][j]!=-1) return d[i][j];
	int v=a[i];
	for(int p=i+1;p<=j;p++){
		v=(v^a[p]);
	}
	int res=0;
	if(v==k1) res=1;
	for(int k=i;k<j;k++){
		res=max(res,dp(i,k)+dp(k+1,j));
	}
	return d[i][j]=res;
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	memset(d,-1,sizeof(d));
   cin>>n>>k1;
   for(int i=1;i<=n;i++){
   	cin>>a[i];
   }
   cout<<dp(1,n);
	return 0;
}
