#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long s=a[i];
			for(int k=i+1;k<=j;k++)s^=a[k];
			if(s==m){
				ans++;
				i=j+1;
			}
			s=0;
		}
	}
	cout<<ans;
	return 0;
}
