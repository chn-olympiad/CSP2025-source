//GZ-S00347 贵阳市华师一学校 田淑文
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,a[N][5],t,maxh,f[N];//当前选了几个人，上一个选的什么？ 
ll cnta,cntb,cntc; 
void dfs(int p,int cnt1,int cnt2,int cnt3,int len){
	if(p==n+1){
		ll num=0;
		for(int i=1;i<=n;i++) num+=a[i][f[i]];
		maxh=max(maxh,num);
		return;
	}
		if(cnt1<len){
			f[p]=1;
			dfs(p+1,cnt1+1,cnt2,cnt3,len);
		}
		if(cnt2<len){
			f[p]=2;
			dfs(p+1,cnt1,cnt2+1,cnt3,len);
		}
		if(cnt3<len){
			f[p]=3;
			dfs(p+1,cnt1,cnt2,cnt3+1,len);
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxh=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0,0,0,n/2);
		cout<<maxh<<endl;
	}
	return 0;
} 
