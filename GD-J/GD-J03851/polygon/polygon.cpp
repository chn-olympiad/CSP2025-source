#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int N=5e5+5;
int n;
long long a[N];
long long ans;
bool use[N];
//long long anss[N];
void dfs(int x,int total,long long sum,long long mx,int last){
	if(x==total+1&&sum>mx*2){
		/*for(int i=1;i<=total;i++){
			cout<<anss[i]<<" ";
		}
		cout<<endl;*/
		ans=(ans+1)%mod;
		return;
	}else{
		for(int i=last;i<=n;i++){
			if(!use[i]){
				use[i]=1;
				//anss[x]=i;
				dfs(x+1,total,sum+a[i],max(a[i],mx),i);
				use[i]=0;
			}
		}
		return;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3){
		cout<<"0";
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(1,i,0,0,1);
	}
	cout<<ans;
	return 0;
}
