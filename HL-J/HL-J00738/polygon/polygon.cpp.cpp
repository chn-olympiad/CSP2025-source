#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sumn,maxn;
void ans(int x){
	if(x>maxn){
			x=maxn;
		}
		if(x>3||x==3){
			sumn+=x;
		}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(sumn==2*maxn){
		cout<<ans<<endl;
	}
    return 0;
}
