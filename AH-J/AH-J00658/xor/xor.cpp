#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int n,k;
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int yhh=a[i];
		for(int j=i;j<=n;j++){
			yhh^=a[j];
			if(yhh==k){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
