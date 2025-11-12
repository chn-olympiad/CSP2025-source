#include<bits/stdc++.h>
using namespace std;
int n,a[10000],tmp=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			tmp=0;
			break;
		}
	}
	if(tmp==1) cout<<n+4;
	else cout<<n+1;
	return 0;
}
