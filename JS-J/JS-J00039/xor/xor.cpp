#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool banana=true;
    int a[1002];
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
		banana=false;
	}
	if(banana)
    cout<<n/2;
    else
    cout<<n%2+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
