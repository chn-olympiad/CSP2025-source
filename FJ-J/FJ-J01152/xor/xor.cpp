#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
