#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
#define L long long
L ans=0,ans2=0,a[N],n,m,b[N],vis[N];
string s;
void dfs(int step){
	if(step==n+1){
		L ans1=0,nw=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'){
				if(b[i]>nw){
					ans1++;
				}
				else nw++;
			}
			else nw++;
		}
		//cout<<ans1<<endl;
		if(ans1>=m){
			ans2++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[step]=a[i];
			dfs(step+1);
			vis[i]=0;
			b[step]=0;
		}
	}
}
int main(){
	//freopen("employ2.in","r",stdin);
	//freopen("employ2.out","w",stdout);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			ans++;
		}
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(ans==n){
		long long ans1=1;
		for(int i=1;i<=n;i++){
			ans1*=i;
			ans1%=99824453;
		}
		cout<<ans1;
	}
	else{
		dfs(1);
		cout<<ans2%998244353;
	}
	return 0;
} 
