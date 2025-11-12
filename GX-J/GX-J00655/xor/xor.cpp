#include <bits/stdc++.h>
using namespace std;
int main()
{
        freopen("xor.in","r",stdin);
        freopen("xor.out","w",stdout);
        int n,k,ans=0;
        cin>>n>>k;
        int m[n];
        for(int i=0;i<=n-1;i++){
			cin>>m[i];
		}
		for(int i=0;i<=n-1;i++){
			if(m[i]^m[i+1]==k){
				ans++;
			}
		}
		cout<<ans;
        return 0;
}

