#include<bits/stdc++.h>
using namespace std;
#define LL long long int
const int N=5005;
LL ans=0;
int a[N],n;
void  dfs(int op,LL cnt,int t){
	if(t>=3&&cnt>2*a[op]){
		ans++;
	}
	for(int i=op+1;i<=n;i++){
		dfs(i,cnt+a[i],t+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1);
	}
	int l=ans%998244353;
	cout<<l;
	return 0;
}
