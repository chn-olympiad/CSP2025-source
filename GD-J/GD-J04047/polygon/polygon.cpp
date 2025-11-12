#include <bits/stdc++.h>
using namespace std;
#define int long long
const int modd=998244353;
int n,l[5001],g_num=0,maxx;
void dfs(int pos,int m_num,int m_ans,int maxx,bool m_flag){
	if(3-m_num>n-pos)return ;
	if(m_num>=3&&m_ans>maxx*2&&m_flag==1)g_num=(g_num+1)%modd;
	if(pos<n){
		dfs(pos+1,m_num+1,m_ans+l[pos+1],max(maxx,l[pos+1]),1);
		dfs(pos+1,m_num,m_ans,maxx,0);
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		maxx=max(maxx,l[i]);
	}
	if(maxx==1){
		cout<<0;
		return 0;
	}
	dfs(0,0,0,0,0);
	cout<<g_num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
