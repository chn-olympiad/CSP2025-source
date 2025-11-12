#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool flag=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1){
			flag=false;
		}
	}
	if (flag){
		int x=1;
		for(int i=1;i<=n;i++)x^=a[i];
		cout<<x;
		return 0;
	}
	int maxn=-1e9;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=0;
			for(int k=i;k<j;k++){
				x+=a[k]^a[k+1];
			}
			maxn=max(maxn,x);
		}
	}
	cout<<maxn;
	return 0;
}
