#include<bits/stdc++.h>
using namespace std;
int w[10001][10001],v[10001][10001],r[10001][10001],a[10001];
int  dp[10001][10001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,cnt=0,sum=0,num=0,b=0,c,n,m,yue=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i];
		for(int j=1;j<=a[i];j++){
			cnt++;
			cin>>w[cnt][j]>>v[cnt][j]>>r[cnt][j]; 
		}
	}
	cnt=0;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=a[i];j++){
			cnt++;
			if(a[i]==2){
			  yue=w[cnt][j]+v[cnt+1][j+1];
			  c=w[cnt][j]+r[cnt+1][j+1];
			  num=r[cnt][j]+w[cnt+1][j+1];
			  n=r[cnt][j]+v[cnt+1][j+1];
			  sum=v[cnt][j]+w[cnt+1][j+1];
			  m=v[cnt][j]+r[cnt+1][j+1];
			  b=max(yue,c);
			  b=max(b,num);
			  b=max(b,sum);
			  b=max(b,n);
			  b=max(b,m);
			  cout<<b<<endl;
			  cnt++;
			  j++;
			}
		}
	}
	return 0;
} 
