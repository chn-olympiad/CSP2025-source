#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		cnt=cnt^a[i];
		if(cnt==k){
			ans++;
			cnt=0;
		}
	}
	cout<<ans;
	return 0;
} 