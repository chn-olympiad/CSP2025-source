#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k;
int a[maxn];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int num=a[i];
			for (int k=i+1;k<=j;k++){
				num+=(! num|a[i]);
			}
			if (num==k){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
