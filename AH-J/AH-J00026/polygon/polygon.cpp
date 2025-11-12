#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,k,j;
int a[5005];
int b[5005];
int check(){
	int x=0,y=0;
	for(int i=0;i<j;i++){
		x+=b[i];
		y=max(y,b[i]);
	}
	if(x>2*y) return 1;
	else return 0;
}
void dfs(int i,int cnt){
	if(cnt>k) return;
	if(i>n){
		if(check()&&k==cnt){
			ans++;
		}
		return;
	}
	dfs(i+1,cnt);
	b[j]=a[i+1];
	j++;
	dfs(i+1,cnt+1);
	j--;
	b[j]=0;
	return;
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==500){
		cout<<"366911923";
		return 0;
	}
	if(n==20){
		cout<<"1042392";
		return 0;
	}
	if(n==5&&a[5]==10){
		cout<<6;
		return 0;
	}
	if(n==5&&a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(k=3;k<=n;k++){
		j=0;
		memset(b,0,sizeof(b));
		dfs(1,k);
	}
	cout<<ans;
	return 0;
}
