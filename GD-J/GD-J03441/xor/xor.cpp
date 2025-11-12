#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool f=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i]){
			f=1;
		}
	}
	if(k==0){
		if(!f){
			cout<<n/2;
		}
		else{
			int cnt=0;
			int n1=n;
			for(int i=1;i<=n;i++){
				if(!a[i]){
					cnt++;
					n1--;
				}
			}
			cout<<cnt+n1/2;
		}
	}
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
