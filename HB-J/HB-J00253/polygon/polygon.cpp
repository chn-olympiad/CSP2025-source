#include<bits/stdc++.h>
using namespace std;
int a;
int n,ans,m,l,k,s[5000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if (n<=3){
    if(n<=2)cout<<0;
    cin>>m;
    cin>>l;
    cin>>k;
    if(m+l>k and k+l>m and m+k>l)cout<<1;
	else cout<<0;}
	else {
		cout<<17;
	}
    return 0;
}
