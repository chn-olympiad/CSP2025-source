#include<bits/stdc++.h>
using namespace std;
long long n,k,mx=0;
long long s=0;
long long l=1,r=0;
long long ans=0;
long long arr[10010];
bool vis[10010][10010];
bool check(int x,int y){
	int an=0;
	for(int i=x;i<=y;i++){
		if(arr[i]==0) continue;
		an=an^arr[i];
		if(an==k&&vis[x][i]==false){
			//cout<<x<<' '<<i<<' '<<an<<endl;
			vis[x][i]=true;
			return true;
		}
		
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(check(j,i)){
				ans++;
				
			}
			
		}
		
	}
	
	cout<<ans;
	return 0;
}
