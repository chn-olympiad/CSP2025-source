#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
	}
	long long js=0;
	int b=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				cnt=1;
				break;
			}
		}if(cnt==1){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					js++;
				}
			}
		}else{
			for(int i=2;i<=n;i+=2){
				js+=n-(i-1);
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				b=(b^a[j]);
				if(b==k){
					js++;
				}
			}
			b=0;
		}
	}
	cout<<js;
	return 0;
}
