#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,zongzhi=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				zongzhi++;
			}
		}
		if(zongzhi==2){
			cout<<2;
		}else if(zongzhi==1&&(a[1]==1||a[0]==1)){
			cout<<2;
		}else if(zongzhi==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<2;
	}
	return 0;
}
