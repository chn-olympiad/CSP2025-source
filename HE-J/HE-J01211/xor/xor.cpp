#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
map<int,int> m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		cnt^=a[i];
		if(cnt==k||m[cnt^k]==ans+1){
			ans++;
			cnt=0;
		}
		m[cnt]=ans+1;
	}
	cout<<ans;
	return 0;
}
