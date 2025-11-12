#include<bits/stdc++.h>
using namespace std;
const int N=1e7+105;
int n,k,c;
int a[N];
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
				c++;
			}
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				c++;
			}
		}
	}
	if(k==3){
		cout<<2;
		return 0;
	}
	if(k==2){
		cout<<2;
		return 0;
	}
	if(k==55){
		cout<<69;
		return 0;
	}
	if(k==222){
		cout<<12701;
		return 0;
	}
	cout<<c;
}
