#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int N=1e7;
ll n,ans=0;
ll l[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	for(int i=3;i<=n;i++){
		for(int j=2;j<=i-1;j++){
			for(int k=1;k<=i-2;k++){
				if(l[j]+l[k]>l[i]) ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 