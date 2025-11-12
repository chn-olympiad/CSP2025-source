#include<iostream>
#include<algorithm>
using namespace std;
int n;
int num[10000];
long long ans=0;//,string jl,jl+(char)(num[i]+'0')
void dfs(int nw,int mx,int tot,int dth){
//	cout<<mx<<jl<<' '<<tot<<' '<<dth<<endl;
	for(int i=1;i<nw;i++){
		dfs(i,mx,tot+num[i],dth+1);
	}
	if(dth>=3&&tot>mx*2){
		ans++;
		ans%=998244353;
//		cout<<mx<<jl<<' '<<tot<<' '<<dth<<endl;
		return;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>num[i];
	sort(num+1,num+n+1);
//	dfs(3,num[3],num[3],1,"");
	for(int i=1;i<=n;i++){
		dfs(i,num[i],num[i],1);
	}
	cout<<ans;
	return 0;
}

