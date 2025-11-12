#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,a[5005];
const long long moshu=998244353;
void dfs(int k,int cnt,int minn){
	if(k==1){
		for(int i=minn+1;i<=n;i++){
			if(cnt>a[i]){
				ans++;
				ans%=moshu;	
			}
		}
		return;
	}
	for(int i=minn+1;i<=n;i++){
		dfs(k-1,cnt+a[i],i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,0,0);
	}
	cout<<ans<<endl;
	return 0;
} 
