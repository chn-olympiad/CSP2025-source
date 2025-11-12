#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
struct{
	int l,r;
}wor[100000];
int n,k;
//int ans=0;
int a[1000000];
cin>>n>>k;
for(int i=1;i<=n;i++){
	cin>>a[i];
   }
   int cnt=0;
for(int i=1;i<=n;i++){
	for(int j=1;j<=n-i+1;j++){
		int nn=a[j],len=1;
		for(int m=j+1;m<=j+i-1;m++){
			nn=nn^a[m];
			len++;
		}
	//	cout<<i<<" "<<j<<" "<<nn<<" "<<len<<endl;
		if(nn==k) {
		    wor[++cnt].l=j;
		    wor[cnt].r=j+i-1;
	    }
	}
}
//	for(int j=1;j<=cnt;j++){cout<<wor[j].l<<" "<<wor[j].r<<endl;}
int dp[100000]={};
for(int i=1;i<=n;i++){
	for(int j=1;j<=cnt;j++){
		if(wor[j].r==i){
			int sss=dp[i];
		//	cout<<dp[i]<<" ";
			dp[i]=max(dp[i-1],dp[wor[j].l-1]+1);
			//cout<<wor[j].l<<" "<<wor[j].r<<" "<<dp[wor[j].l-1]<<" ";
			dp[i]=max(sss,dp[i]);
		//	cout<<dp[i]<<endl;
		}
	}
}
   cout<<dp[n];
}
