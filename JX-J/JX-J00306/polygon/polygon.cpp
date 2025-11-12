#include<bits/stdc++.h>
using namespace std;
int b[5001],n,cnt;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>b[i];
    if(n<3) cout<<1;
    else cout<<(n-1)*(n-2)/2;
	return 0;
}
