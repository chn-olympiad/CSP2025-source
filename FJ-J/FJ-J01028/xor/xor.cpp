#include<bits/stdc++.h>
using namespace std;
long long a[100006],n,k,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=-1;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
			}else{
				if(a[i+1]==1){
					cnt++;
					i+=1;
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}else{
				if(a[i+1]==0){
					cnt++;
					i+=1;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
