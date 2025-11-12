#include<bits/stdc++.h>
using namespace std;
long long n,a[5006],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++){
		int k=i;
		for(int j=i+1;j<=n-1;j++){
			k+=j;
			for(int p=j+1;p<=n;p++){
				if(k<=a[p]){
					break;
				}
				else{
					ans++;
					if(ans>998244353){
						ans-=998244353;
				 	}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
