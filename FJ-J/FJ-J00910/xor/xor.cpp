#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,ans=0,a[N],mmax=-1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>a[i]; 
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(x==k){
			ans++;
		} 
		for(int j=i+1;j<=n;j++){
			x=(x xor a[j]);
			if(x==k){
				ans++;
			}
		}
	}
	cout <<ans;
	return 0;
}
