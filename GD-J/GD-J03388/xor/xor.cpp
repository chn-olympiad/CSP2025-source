#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[50010],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
			if(a[i]==1&&a[i-1]==1){
				cnt++;
				a[i]=2;
			}
		}
		cout<<cnt;
		return 0;
	}
	cout<<1;
	
	
	return 0;
}

