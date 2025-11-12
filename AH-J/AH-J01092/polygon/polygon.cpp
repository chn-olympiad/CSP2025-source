#include<bits/stdc++.h>
using namespace std;

long long n,cnt=0;
long long  a[10010],b[10000],c[100000],ans;
bool cmp (int x,int y){
	return x>y;
}
void dfs(int i,int k,int cnt){
	c[k]=a[i];
	if(k>=3){
		sort(c,c+k,cmp);
		if(cnt>2*c[0]){
			ans++;
			ans%=998244353;
		}
	}
	if(k>=3)
	b[k]=i;
	if(i<n){
	dfs(i+1,k+1,cnt+a[i]);
	dfs(i+1,k,cnt);
}
	c[k]=0;
	return;

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	
	}

	dfs(0,0,0);
	cout<<ans;
	return 0;
}
