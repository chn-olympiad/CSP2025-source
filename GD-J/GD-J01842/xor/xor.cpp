#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],cnt[N];
int n,k;
int f(int x){
	for(int j=x;j<=n;j++){
		for(int i=x;i<=j;i++){
			if((cnt[j]^cnt[i-1])==k){
				return f(j+1)+1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=a[i]^cnt[i-1];
	}
	cout<<f(1)<<endl;
	return 0;
} 
