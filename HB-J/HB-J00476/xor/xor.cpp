#include <bits/stdc++.h>
using namespace std;
int a[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
	int ans=a[i]|a[i];if(ans==k){cnt++;continue;}
		ans=a[i];
		for(int j=i+1;j<=n;j++){
			ans|=a[j];
			if(ans==k){
				i=j;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
