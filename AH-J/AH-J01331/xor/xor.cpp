#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int j=i,x=1;
		while(j<=n){
			if(j==i){
				x=a[j];
			}else{
				x^=a[j];
			}
			if(x==k){
				i=j;
				cnt++;
				break;
			}
			j++;
		}
	}
	cout<<cnt;
	return 0;
}
