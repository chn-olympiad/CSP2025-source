#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p=n*m;
    int a[p+1];
    for(int i=1;i<=p+1;i++){
        cin>>a[i];
    }
    int x=a[1],y;
    sort(a+1,a+p+1);
    for(int i=1;i<=p+1;i++){
        if(a[i]==x){
            y=i;
            break;
        }
    }
    int l,h;
    l=(y-1)/n+1;
    h=y%(2*n);
    if(h==0){
        h=1;
    }else
    if(h>n){
        h-=n;
        h=n+1-h;
    }
    cout<<l<<' '<<h;
	return 0;
}
// ACPLS