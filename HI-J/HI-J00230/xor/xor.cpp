#include<bits/stdc++.h>
using namespace std;

long long ans=0, cnt=0, n, k;
int a[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int r=0, l=0;
	while(r<n){
		for(int i=l; i<=r;i++){
			ans = ans^a[i];
		}
		if(ans==k){
			cnt++;
			l=r+1;
			r = l;
			continue;
		}
		l++, r++;
	}
	
	cout << cnt;
	
	return 0;
}
