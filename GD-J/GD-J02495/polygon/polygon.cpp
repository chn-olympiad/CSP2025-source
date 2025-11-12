#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=998244353;

int a[5005];
int n;
ll ans;
void dfs(int nw,int mx,int sm){
	if(sm>2*mx){
//		cout<<sm<<" "<<mx<<endl;
		ans++;
		ans%=M;
	}
//	cout<<nw<<" ";

	
	for(int i=nw+1;i<=n;i++){
//		cout<<sm<<" "<<mx<<endl;
		dfs(i,max(mx,a[i]),sm+a[i]);
		
	}
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);

	cout<<ans;
} 

