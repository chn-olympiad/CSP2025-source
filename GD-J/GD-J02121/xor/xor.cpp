#include <bits/stdc++.h>
#include <cmath>
using namespace std;
unsigned long long a[1000000];
int vis[1000000];
int x(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++)sum = sum xor a[i];
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n;
	unsigned long long k;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int cnt=0;
	for(int i=0;i<n;i++){
		if(vis[i] == 1)continue;
		for(int j=i;j<n;j++){
			if(vis[j] == 1)continue;
			if(x(i,j) == k){
				for(int z=i;z<=j;z++){
					vis[z] = 1;
				}
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
