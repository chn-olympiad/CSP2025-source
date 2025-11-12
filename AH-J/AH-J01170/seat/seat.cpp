#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[110],t,x,y;
bool cmp(LL a,LL b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			x=(i-1)/n+1;
			if(x%2==1){
				y=i-n*(x-1);
			}
			else{
				y=n*x-i+1;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
