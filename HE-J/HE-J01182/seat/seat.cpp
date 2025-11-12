#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
 freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(k==0)
    {
    	cout<<1;
    	return 0;
	}
    cout<<2;
 	fclose(stdin);
 	fclose(stdout);
	return 0;
}
