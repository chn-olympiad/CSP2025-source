#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,k,lis[N],l,r,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>lis[i];
	for(int i=1;i<=n;i++)
	lis[i]^=lis[i-1];
	r=1;l=0;
	for(;r<=n;r++)
	for(int i=l;i<r;i++)
	if((lis[r]^lis[i])==k){
		l=r;
		cnt++;
		break;
	}
	cout<<cnt;
	return 0;
} 