#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[5005];
bool vis[5005];
vector<int>u;
long long ans;
void find(int cnt){
	if(cnt==0){
		int len=u.size();
		int mmax=-1,ssum=0;
		for(int i=0;i<len;i++){
			ssum+=u[i];
			mmax=max(mmax,u[i]);
		}
		if(ssum>mmax*2){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			u.push_back(i);
			find(cnt-1);
			u.pop_back();
			vis[i]=0;
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		find(i);
	}
	cout<<ans;
    return 0;
}
