#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	int cnt=1;
	for(int j=1;j<=n;j++){
		int yhh=0;
		for(int i=cnt;i<=j;i++){
			yhh=yhh^a[i];
		}
		for(int i=cnt;i<=j;i++){
			if(yhh==k){
				cnt=j+1;
				ans++;
				break;
			}
			yhh^=a[i];
		}
	}
	cout<<ans;
	return 0;
} 
