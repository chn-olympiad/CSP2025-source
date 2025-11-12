#include<bits/stdc++.h>
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
int n;
int a[5010];
int ans=0;
bool judge(int sum,int maxx){
	maxx*=2;
	if(maxx>=sum) return false;
	else return true;
}
void dfs(int maxx,int num,int sum){
	if(num==n){
		if(judge(sum,maxx)==true){
//			cout<<sum<<" "<<maxx<<endl;
			ans++;return ;
		} else return ;
	}
	num++;
//	cout<<a[num]<<" "<<num<<" "<<sum+a[num]<<endl;
	dfs(a[num],num,sum+a[num]);
//	cout<<a[num-1]<<" "<<num<<" "<<sum<<endl;
	dfs(maxx,num,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	I AK CSP
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}else if(n<=20){
		dfs(0,0,0);
		cout<<ans;
	}else if(n<=500 && a[n]!=1){
		dfs(0,0,0);
		cout<<ans;
	}else if(a[n]==1){
		int x=1,y=1;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=i;j++){
				x*=j;
			}
			for(int j=1;j<=i;j++){
				y*=(n-j+1);
			}
			ans+=y/x;
		}
		cout<<ans;
	}
	else {
		dfs(0,0,0);
		cout<<ans;
	}
	return 0;
}