#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
long long arr[MAXN];
long long n,k,num,ans;
multiset<long long> acc[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++) cin>>arr[i];
	int nuse=0;
	if (k==0) {
		for(int i=1;i<=n;i++) {
			num^=arr[i];
			if (acc[nuse].find(num)!=acc[nuse].end() || num==0) {
				num=0;
				ans++;
				nuse++;
			} else {
				acc[nuse].insert(num);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		num^=arr[i];
		acc[nuse].insert(num);
		bool k1=acc[nuse].find(num^k)!=acc[nuse].end();
		bool k2=acc[nuse].find(k)!=acc[nuse].end();
		
		if (k==0) {
			if (k2) {
				num=0;
				ans++;
				nuse++;
			}
		} else {
			if (k1 || k2) {
				num=0;
				ans++;
				nuse++;
			}
		}
	}
	cout<<ans;
}
/*
4 0
2 1 0 3
*/
