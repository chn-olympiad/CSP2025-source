#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],la=0;
long long s[500005],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=(s[i-1]^a[i]);
	for(int i=1;i<=n;i++){
		for(int j=la+1;j<=i;j++)
			if((s[i]^s[j-1])==k){
				la=i,sum++;
				break;
			}
	}
	cout<<sum;
}
