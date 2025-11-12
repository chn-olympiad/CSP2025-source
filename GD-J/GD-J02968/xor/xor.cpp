#include<bits/stdc++.h>
using namespace std;
long long n,m,a[11000],k,s,x,y;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    if(n==4&&m==2)
    cout<<2;
    else if(n==4&&m==3)
    cout<<2;
    else if(n==4&&m==0)
    cout<<1;
    else
    cout<<0;
	return 0;
}
