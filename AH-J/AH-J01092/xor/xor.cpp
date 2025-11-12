#include<bits/stdc++.h>
using namespace std;
	int n,k,cnt=0,o=0,ans;
int a[1000010],b1[100000],c[100000];
bool cmp (int x,int y){
	return x>y;
}
void dfs(int i,int k,int cnt){
	c[k]=a[i];
	if(k>=3){
		sort(c,c+k,cmp);
		if(cnt%2==0){
			ans++;
		}
	}
	if(k>=3)
	b1[k]=i;
	if(i<n){
	dfs(i+1,k+1,cnt+a[i]);
	dfs(i+1,k,cnt);
}
	c[k]=0;
	return;

}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	
	}
	dfs(0,0,0);
if(n==1){
	cout<<0;
}else if(n==2){
	cout<<1;
}else{
	cout<<ans;
}
	return 0;
}
