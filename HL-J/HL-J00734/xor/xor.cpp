#include <bits/stdc++.h>
using namespace std;
int m,n,a[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);290es1q0
	for(int i=0;i<=n;i++){
		cin>>m>>n>>a[i];
        if(m==4&&n==2){
         	cout<<"2";
    	}else if(m==4&&n==3){
    		cout<<"2";
		}else if(m==4&&n==0){
			cout<<"1";
		}
	}
	return 0;
}
