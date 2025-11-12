#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,c,r,ls,mod,lie,hang;
int a[186];
int muti(long long x,long long y){
	if(x%y==0) return x/y;
	else return x/y+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
    	if(i==1) ls=a[i];
    }
    sort(a+1,a+1+n*m);
    long long ip=lower_bound(a+1,a+1+n*m,ls)-a;
    ip=n*m+1-ip;
    hang=ip%n;
    lie=muti(ip,n);
    if(hang==0) hang=n;
    if(lie%2==0){
        hang=n+1-hang;
    }
    cout<<lie<<" "<<hang;
	return 0;
}
