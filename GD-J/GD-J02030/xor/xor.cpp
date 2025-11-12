#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],b[N],ans=0,n,k;
void findd(int q){
	if(q>n){
		return;
	}
	int ww=0;
	for(int j=q;j<=n;j++){
		if(a[q]==k){
			ww=1;
			ans++;
			findd(j+1);
			return;
		}else if((b[j]^b[q-1])==k){
			ww=1;
			ans++;
			findd(j+1);
			return;
		}
	}
	if(ww==0)findd(q+1);
	return;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	int maxa=-1;
	for(int i=1;i<=n;i++){
		findd(i);
		maxa=max(maxa,ans);
		ans=0;
	}
	cout<<maxa;
	return 0;
} 
