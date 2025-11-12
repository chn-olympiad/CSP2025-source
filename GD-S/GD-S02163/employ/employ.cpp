#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000000],c[1000000],ans,t;
bool bz[1000000];
string s;
void dp(int x){
	if(x>n){
		t=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||t>=a[c[i]]) t++;
		}
		if(t<=n-k) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!bz[i]){
			bz[i]=1;
			c[x]=i;
			dp(x+1);
			bz[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	s="0"+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp(1);
	printf("%d",ans);
} 
