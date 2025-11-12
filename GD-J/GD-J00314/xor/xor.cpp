#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int s[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	s[0]=0;
	for(int i=1;i<=n;i++)
		s[i]=(s[i-1]^a[i]);
	int ans=0;
	int o=1;
	for(int i=1;i<=n;i++){
		for(int j=o;j<=i;j++){
			if((s[i]^s[j-1])==m)
			{
				o=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
