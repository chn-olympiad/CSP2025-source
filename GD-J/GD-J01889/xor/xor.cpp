#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==n)continue;
			if(a[i]==1&&a[i+1]==1){
				cnt++;
				i++;
			}
		}
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

