#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[500101];
int ans=0;
int q[500101];
int l=0;
int vis[2500101];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			for(int j=l;j<=i;j++){
				int o=q[j]^q[l];
				vis[o]=0;
			}
			l=i;
		}
		else{
			int maxn=(q[i]^q[l])^k;
			if(vis[maxn]==1||maxn==0){
				ans++;
				for(int j=l;j<=i;j++){
					int o=q[j]^q[l];
					vis[o]=0;
				}
				l=i;
			}
			else{
				vis[maxn^k]=1;
			}
		}	
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}