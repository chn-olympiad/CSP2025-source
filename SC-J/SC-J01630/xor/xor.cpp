#include<bits/stdc++.h>
using namespace std;
int main(){
	//记得加一个freopen!
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,e=0,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a==0){
			e=1;
		}
	}
	if(e==1){
		cout<<1;
	}
	return 0;
}
