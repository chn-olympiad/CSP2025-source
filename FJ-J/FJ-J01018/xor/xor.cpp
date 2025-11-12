#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int k;
int a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
			}else{
				if(a[i+1]!=a[i]){
					cnt++;
					i++;
				}
			}
		}
		cout<<cnt;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			} 
		}
		cout<<cnt;
	}
	return 0;
}
