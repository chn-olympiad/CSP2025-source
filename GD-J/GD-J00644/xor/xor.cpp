#include<bits/stdc++.h>
using namespace std;

int a[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	int prer = 0;
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		int x = 0;
		for(int j = i;j <= n;j ++){
			x = (x^a[j]);
			if(x == k){
				ans++;
				prer = j;
				break;
			}
			
		}
		i = prer;
	}
	cout << ans;
	return 0;
}
