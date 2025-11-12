#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,maxq=-1,cnt;
int b[500005];
ll x[500005],a[500005];
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			int tmp=a[i];
			for(int y=i+1; y<=j; y++)
			{
				tmp^=a[y];
			}
			if(tmp==k){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
