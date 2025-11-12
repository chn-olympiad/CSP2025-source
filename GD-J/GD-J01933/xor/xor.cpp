#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long a[N];
long long n,k;
long long ans=0;
bool vis[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			vis[i]=true;
		}
	}
	if(k==0){//ÏàÁÚµÄ1 
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(a[i+1]==1){
					ans++;
					vis[i+1]=true;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
