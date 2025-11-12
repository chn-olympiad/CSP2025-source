#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
bool mp[5*N+5];
int a[5*N+5],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=0;
			for(int e=i;e<=j;e++){
				sum^=a[e];
			}
			if(sum==k){
				bool flag=0;
				for(int e=i;e<=j;e++){
					if(mp[e]){
						flag=1;
						break;
					}
				}
				if(!flag){
					for(int e=i;e<=j;e++){
						mp[e]=1;
					}
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
