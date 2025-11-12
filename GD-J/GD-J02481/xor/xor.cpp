#include <bits/stdc++.h>
using namespace std;

int n,k,ans;
int a[500005];

bool pd(int l,int r){
	int s=a[l];
	for(int i=l+1;i<=r;i++){
		s=s^a[i];
	}
	if(s==k) return 1;
	return 0;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] == k){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(pd(i,j)){
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
