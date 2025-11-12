#include<bits/stdc++.h>
using namespace std;
int n,m;
int k=0;
int c[505];
string a;
bool mark[20]={0};
int dfs(int ti,int lu){
	int ans=0;
	if(ti==n+1){
		if(lu>=m)return 1;
		else return 0;
	}
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			mark[i]=1;
			if(c[i]>=ti-lu&&a[ti]=='1'){
				ans+=dfs(ti+1,lu+1);
			}else ans+=dfs(ti+1,lu);
			mark[i]=0;
		}	
	}
	return ans;
}
void solve1(){
	int ans=dfs(1,0);
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)cin>>c[i];
	a='0'+a;
	for(int i=1;i<=n;i++){
		if(a[i]=='1'){
			k++; 
		}
	}
	if(k<m){
		cout<<0;
		return 0;
	}
	if(k==m){
		long long ans=1;
		int tm=0;
		for(int i=n;i>=1;i--){
			if(a[i]=='1'){
				int te=0;
				for(int j=1;j<=n;j++){
					if(c[j]>i-k+tm)te++;
				}
				te-=tm;
				ans*=te;
				if(te<=0){
					cout<<0;
					return 0;
				}
				tm++;
				ans%=998244353;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(c+1,c+1+n);
		solve1();
	return 0;
} 
