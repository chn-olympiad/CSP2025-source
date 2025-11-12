#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++)cin>>a[i];
	ll x,y;
	//pair<ll,ll> ans[n+5];
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
		{
			if(j==i)x=a[j];
			else x^=a[j];
			if(x==m){
			//	ans[cnt]={i,j};
				//cout<<ans[cnt].first<<' '<<ans[cnt].second<<endl;
				i=max(i,j)+1;
				cnt++;
			}
		}
	}
	cout<<cnt-1;
	return 0;
} 
/*
CCF CSP-J/S 2025 RP++
当前题目：J T3 
赛时预估：最高40pts 大约25pts 保底10pts 黄题 
版权所有 请勿翻录
陈彦羽
2025/11/1
惠州中学
*/ 
