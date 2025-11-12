#include<bits/stdc++.h>
using namespace std;
struct p{
	int s,b;
}a[500005];
int n,k,sum = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		a[i].b = 0;
		if(a[i].s == k){
			sum++;
			a[i].b = 1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=i-1;j<i;j++){
			if(a[i].s+a[j].s == k && a[i].b == 0 && a[j].b == 0){
				sum++;
				a[i].b = 1;
			}
		}
	}
	cout<<sum;
	return 0;
}
