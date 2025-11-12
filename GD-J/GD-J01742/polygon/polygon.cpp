#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n;
	cin >> n;
	int a[5555];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j-i+1 >= 3){
				int s=0, sm=0;
				for(int k=i;k<=j;k++){
					s = max(s,a[k]);
					sm += a[k];
				}
				if(sm > 2*s){
					ans++;
				}
			}
		}
	}
	cout << ans;
    return 0;
}

