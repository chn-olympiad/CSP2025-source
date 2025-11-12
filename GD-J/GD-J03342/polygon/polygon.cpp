#include<bits/stdc++.h>
using namespace std;
long long n,ans,arr[510];
struct node{
	long long a,m;
} brr[510][510];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			brr[i][j].a = brr[i][j-1].a + arr[j];
			brr[i][j].m = max(brr[i][j-1].m,arr[j]);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(j-i+1>=3 && brr[i][j].a > brr[i][j].m*2) ans++;
		}
	}
	cout << ans;
	return 0;
} 
