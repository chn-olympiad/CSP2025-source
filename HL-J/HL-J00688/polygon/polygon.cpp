#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5010;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int sum=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>maxn) maxn=a[i];
		sum+=a[i];
	}
	if(sum>(maxn*2))cout << 1;
	else cout << 0;
	return 0;
}
