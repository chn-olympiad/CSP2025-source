#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,ans;
int a[N];
int t[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			t[i]=1;
			ans++;
		}
		else if(a[i-1]!=k&&t[i-1]==0&&k==0){
			ans++;
			t[i]=1;
			t[i-1]=1;
		}
	}
	cout<<ans;
	return 0;
}
// q.7
//~l2
//ÉÏÉÆÈôË® 
//4 3 6 4 
