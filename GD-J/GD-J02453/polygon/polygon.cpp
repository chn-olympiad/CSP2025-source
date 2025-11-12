#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5033;
const int P=998244353;
int n;
int a[N];
ll ans=0;
void dfs(int num,int last,ll sum){
	if(num>=n){
		return;
	}
	for(int i=last;i<=n;i++){
		sum+=a[i];
		last=i+1;
		num++;
		if(sum>a[i]*2&&num>=3){
			ans++;
			ans%=P;
		}
		dfs(num,last,sum);
		sum-=a[i];
		num--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	sort(a+1,a+n+1);
	if(flag==1){
		for(int i=3;i<=n;i++){
			int x=1,y=1;
			for(int j=1;j<=i;j++){
				x*=n-j+1;
				y*=j;
			}
			ans+=((x/y)%P);
		}
	}
	else{
		dfs(0,1,0);
	}
	cout<<ans;
	return 0;
}
