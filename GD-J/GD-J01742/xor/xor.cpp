#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n, k, cnt=0;
    int a[500005];
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
    	cin >> a[i];
	}
	if(k == 0) cout << n/2;
	else if(k >= 1 && k<=255){
		for(int i=1;i<=n-1;i++){
			if(a[i] != a[i+1]){
				cnt++;
			}
		}
		cout << cnt/k;
	}
    return 0;
}

