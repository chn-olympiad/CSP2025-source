#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],l=1,r=1,cnt;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >>k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	while(l<=n){
		int c = 0;
		for(int i = l;i<=r;i++){
			c=c xor a[i];
		}
		if(c==k||r==n){
			cnt++;
			l=r+1;
			r=l;
		}
		else r++;
	}
	cout << cnt <<endl;
	
	return 0;
}
