#include<bits/stdc++.h>
using namespace std;
int n,m,a[111];
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
        cin>>a[i];
    int t=a[0],p=0;
    sort(a,a+n*m,cmp);
    for(;a[p]!=t;p++) continue;
    p++;
    if(p%n==0)
        cout<<(p/n)<<" "<<(((p/n)%2==1)? n:1);
    else
        cout<<(p/n+1)<<" "<<(((p/n)%2==0)? (p%n):(n+1-p%n));
	return 0;
}
