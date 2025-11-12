#include <bits/stdc++.h>
using namespace std;
int a[5010],ans[5010],b[5010],t[5010];
int cnt,r,n;
const long long N=998244353; 
void dfs(int x,int pre){
	if(x-1==r){
		int sum_=0,mx_=-1999;
		for(int i=1;i<=r;i++){
			//cout<<ans[i]<<" ";
			sum_+=ans[i];
			mx_=max(mx_,ans[i]);
		}
		//cout<<"\n";
		if(sum_>mx_*2) cnt++;
		return ;
	}
	for(int i=1;i<=n;i++){
		int con=a[i];
		if(con<pre) continue;
		if(b[con]>=t[con]) continue;
		b[con]++;
		ans[x]=con;
		dfs(x+1,con);
		b[con]--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int sum=0,mx=-19999;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
		sum+=a[i];
		mx=max(mx,a[i]);	
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(sum<=mx*2){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		r=i;
		dfs(1,a[1]);
	}
	cout<<cnt%N;
	return 0;
}

