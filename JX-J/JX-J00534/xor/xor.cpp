#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,k,qzh[500010],ans;
bool vis[500010];
int main(){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(a[i]==k){
			//ans++;
			qzh[i]=qzh[i-1]^a[i];
		}
		else{
			
			qzh[i]=qzh[i-1]^a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(qzh[i]==k) ans++;
	}
	cout<<ans;
	
	return 0;
}
