#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],tmp,ans=0,lft;
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>lft;j--){
			tmp^=a[j];
			if(tmp==k){
				ans++;
				lft=i;
				break;
			}
		}
		tmp=0;
	}
	cout<<ans;
	return 0;
} //I love you,my dearing,marry me please.！