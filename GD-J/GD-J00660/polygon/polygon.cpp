#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	vector<int>v(n+1),a(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
		a[i]=a[i-1]+v[i];
	}for(int len=2;len<n;len++){
		for(int i=1;i<=n-len;i++){
			bool key=0;
			int maxi=0;
			for(int j=i;j<i+len;j++){
				if(a[i+len]-a[i-1]-v[j]<v[j]){
					key=1;
					break;
				}maxi=max(maxi,v[i]);
			}if(key)continue;
			if(a[i+len]-a[i-1]>2*maxi)ans++;
		}
	}cout<<ans%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

