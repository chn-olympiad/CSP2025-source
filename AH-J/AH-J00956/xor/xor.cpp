#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    int i;
    int fi=1;
    for(i=1;i<=n;i++){
        if((b[i]^b[fi-1])==k){
			for(int j=fi;j<=i;j++){
				a[j]=-1;
			}
            ans++;
            fi=i+1;
        }
    }
	for(i=1;i<=n;i++){
		if(a[i]==k)ans++;
	}
	cout<<ans;
    return 0;
}
