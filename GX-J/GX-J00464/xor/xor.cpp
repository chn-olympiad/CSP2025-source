#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5*5+5;
int n,k,ans=0;
int a[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=i;	
	return 0;
}
