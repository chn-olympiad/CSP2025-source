#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005],tong[305],cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			tong[a[i]]++;
		}
	}
	for(int i=1;i<=300;i++){
		if(tong[i]>=2){
			cnt+=tong[i]/2;
		}
	}
	if(k>=1){
		cout<<n/2;
	}else{
		cout<<cnt;
	}
	
	return 0;
}
