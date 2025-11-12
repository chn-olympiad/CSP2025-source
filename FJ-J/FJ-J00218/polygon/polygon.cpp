#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return f*x;
}
int n,a[5005],ans[5005],l=1,t;
void dfs(int d){
	if(d==n+1){
		int ma=0,cnt=0;
		for(int i=1;i<l;i++){
			cnt+=ans[i];
			//cout<<ans[i]<<' ';
			ma=max(ma,ans[i]);
		}
		//cout<<cnt<<' '<<ma<<' '<<l<<'\n';
		if(cnt>ma*2&&l>=4){
			t++;
			t%=998244353;
		}
		return;
	}
	dfs(d+1);
	ans[l]=a[d];
	l++;
	dfs(d+1);
	l--;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<t;
	return 0;
}

