#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int p=1;p<=n;p++){
		for(int j=p;j<=n;j++){
			int k=a[p];
			for(int c=p+1;c<=j;c++){
				k=k^a[c];
			}
			if(k==m){
				ans++;
				p=j;
				j=n+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
