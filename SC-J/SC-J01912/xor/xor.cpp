#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t;
	for(int i=1;i<=n;i++){
		t=a[i];
		if(t==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			t=t^a[j];
			if(t==k){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
//			cout<<t<<" ";
//		cout<<"\n";
/*
4 2
2 1 0 3
4 3
2 1 0 3
4 0
2 1 0 3
*/