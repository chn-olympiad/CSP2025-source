#include<bits/stdc++.h>

using namespace std;
const long long mod=998244353;
int ans=0;
int n;
int a[5010];
void DFS(int sum,int id,int mx,int num){
	if(num>=2){
		int i=0;
		bool f=false;
		for(i=n;i>id;i--){
			if(a[i]<sum) {
				f=true;
				break;
			}
		}	
		if(f==true){
			ans+=i-id; 
			ans%=mod;
		}
	}
	for(int i=id+1;i<=n;i++){
		
		DFS(sum+a[i],i,a[i],num+1);
	}
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	DFS(0,0,0,0);
	cout<<ans;
}
