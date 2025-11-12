#include<bits/stdc++.h>
using namespace std;
int n,k,a[500002],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++;
		else{
			if(i<=n-1&&a[i]==a[i+1]){
				ans++;i++;
			}
		}
	}
	cout<<ans;
}

