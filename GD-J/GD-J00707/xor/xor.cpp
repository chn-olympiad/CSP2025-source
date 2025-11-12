#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500010],ans,vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int ad=0;l+ad<=n;ad++){//与右区间的差 
			int tmp=0;
			bool flag=1;
			for(int i=l;i<=l+ad;i++){
				if(!vis[i]) tmp=(tmp^a[i]);
				else{
					flag=0;
					break;
				}
			}
			if(tmp==k&&flag){
				ans++;
				for(int i=l;i<=l+ad;i++){
					vis[i]=1;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
