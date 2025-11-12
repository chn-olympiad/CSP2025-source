#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1],b[m+1];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	cout<<a[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

