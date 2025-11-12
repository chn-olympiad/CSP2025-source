#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],s[500005],b[500005];
vector<int>vt[2000005];
int ans;
bool check(int i,int j){
	for(;i<=j;i++)if(b[i]==1)return false;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	s[1]=a[1];
	for(int i=2;i<=n;i++)s[i]=a[i]^s[i-1];
	for(int i=1;i<=n;i++)vt[s[i]].push_back(i);
	for(int i=1;i<=n;i++){
		int x=s[i]^k;
		if(a[i]==k){
			ans++;
			b[i]=1;
			continue;
		}
		if(check(1,i)&&x==0){
			for(int k=1;k<=i;k++)b[k]=1;
			ans++;
		}
		for(int j=0;j<vt[x].size();j++){
			int y=vt[x][j];
			if(y==0)continue;
			if(y>=i)break;
			if(check(y+1,i)){
				for(int k=y+1;k<=i;k++)b[k]=1;
				vt[x][j]=0;
				ans++;
				break;
			} 
			
		}
	}
	cout<<ans;
	return 0;
} 
