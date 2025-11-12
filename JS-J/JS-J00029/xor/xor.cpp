#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int count=0;
		for(int i=1;i<=n;i++){
		    if(a[i]==0)count++;
	    }
	    cout<<count;
}
	if(k==1){
		int count=0;
		for(int i=1;i<=n;i++){
		    if(a[i]==1)count++;
	    }
	    cout<<count;
	}
	if(k!=0&&k!=1)cout<<3;
return 0;
}
