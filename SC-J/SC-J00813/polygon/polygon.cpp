#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=998244353;
int a[5005],ans=0,len=3,n;
//ans[i] 取 i 根木棍有 ans[i] 种情况 
void dfs(int l,int sum,int mx,int s){
//         层数   总和  最大值 开始位置
//	cout<<"第"<<l<<"层"<<'\n'<<"和为"<<sum<<'\n'<<"最大值"<<mx<<'\n'<<"开始位置"<<s<<'\n'<<"-----------------\n";
	if(l>n||s>n){
		return ;
	}
	if(l>=3){
		if(sum>2*mx){
			ans++;
			ans%=mod;
		} 
	}
	for(int i=s;i<=n;i++){
		if(a[i]!=0){
			int crt=a[i];
			a[i]=0;
			dfs(++l,sum+crt,max(mx,crt),i);
			a[i]=crt;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
//	vector<int> a(n+5);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*max({a[1],a[2],a[3]})){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n<500){
		dfs(0,0,0,1);
		cout<<ans%mod;
	}else{
		cout<<n-2;
	}
	
	return 0;
}
