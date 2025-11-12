#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,minn=1e5+3,maxn=-1,cnt=0,num=0;
	cin >> t;
	for (int i=1;i<=t;i++) {
		cin >> n;
		int a[n];
		for (int i=0;i<n;i++) {
			cin >> a[i];
			if (a[i]>maxn) {
				maxn=a[i];
				cnt+=a[i];
			}
			num+=a[i];
			cnt=0;
		}
	}
	cout << num << endl;
	return 0;
}
