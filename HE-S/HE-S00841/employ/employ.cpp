#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[510],ans;
bool vis[101];
string s;
void lie(int k,int lian,int q){
	if(n-k+1+q<m)return ;
	if(k>n){
		if(q>=m)ans=(ans+1)%998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a[i]<=lian||s[k-1]=='0')lie(k+1,lian+1,q);
			else lie(k+1,0,q+1);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	lie(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//hope 10
