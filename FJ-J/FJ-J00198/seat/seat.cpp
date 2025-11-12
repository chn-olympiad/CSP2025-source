#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],t,s,h,l;
bool cmp(int a,int b){
    return a>b;	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    t=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
    	if(t==a[i]){
    		s=i;
    		break;
		}
	}
	l=(s+n-1)/n;
	if(l%2==1) h=s-(l-1)*n;
	else h=n-(s-(l-1)*n)+1;
	cout<<l<<" "<<h;
	return 0;
}
