#include<bits/stdc++.h>
using namespace std;
int n,k1,h;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k1;
	if(k1==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=0;
			for(int k=i;k<=j;k++){
				x+=a[k];
			}
			if(x==k1){
				h++;
			}
		}
	}
	cout<<h;
	return 0;
}
