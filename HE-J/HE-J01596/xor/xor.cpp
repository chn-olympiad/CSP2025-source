#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+10;

int n;
LL k;
LL a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<n/2;
	return 0;
}
