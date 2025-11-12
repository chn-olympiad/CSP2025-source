#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[300];
bool vis[300];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		if(a[i]==k){
			vis[i]=1;
			ans++;
			continue;
		}
		long long x=a[i];
		for(int j=i+1;j<=n;j++){
			x^=a[j];
			if(x==k){
				ans++;
				for(int y=i;y<=j;y++)
					vis[y]=1;
				break;
			}
		}	
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
