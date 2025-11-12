#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int ans=0;
struct cf{
	int s;
	int e;
}b[1050];
int dp[1050][1050]={0};
int yh(int x,int y){
	return x^y;
}
bool cmp(int f,int g){
	return f<g;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1][1]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=a[i];
			for(int l=i+1;l<=j;l++){
				dp[i][j]=yh(dp[i][j],l);
				if(dp[i][j]==k){
					ans++;
					b[ans].s=i;
					b[ans].e=j;
				}
			}
		}
	}
	for(int i=1;i<=ans;i++){
		for(int j=i+1;j<=ans;j++){
			if(b[i].e>b[j].e) swap(b[i].e,b[j].e);
		}
	}
	for(int i=1;i<=ans;i++){
		if(b[i].e<b[i+1].e&&b[i].e>b[i+1].s) ans--;
		else if(b[i].s<b[i+1].s&&b[i].s<b[i+1].e) ans--;
		else if(b[i].s>b[i+1].s&&b[i].e<b[i+1].e) ans--;
	}
	cout<<ans;
	return 0;
}
