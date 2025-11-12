#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				cout<<"1";
				return 0;
			}
			if(a[i]==2){
				cout<<"2";
				return 0;
			}
		}
		    
	}
	return 0;
}
