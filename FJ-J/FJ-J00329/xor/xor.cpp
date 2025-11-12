#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x,y;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==0) x++;
    	else y++;
	}
	if(k==0&&x==0) cout<<n/2;
	else if(k==0) cout<<x+y/2;
	else cout<<y;
	return 0;
}
