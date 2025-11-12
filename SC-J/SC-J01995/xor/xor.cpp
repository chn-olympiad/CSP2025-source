#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010],s[500010],top,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int j=1;j<=n;j++){
		if(a[j]==k){
			top=j;
			ans++;
		}
		for (int i=top;i<j;i++){
			if((s[i]^s[j])==k){
				ans++;
				top=i+1;
				break;
			}
		}
	}
	cout<<ans;
}