#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans=0;
ll a[N],k,num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			continue;
		}else{
			for(int j=i;j<=n;i++){
				num^=a[j];
				if(k^a[i]==num){
					ans++;
					continue;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
