#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int x,c,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    c = n*m;
    cin>>x;
    a[1] = x;
    for(int i = 2;i <= c;i++){
        cin>>a[i];
    }
    sort(a+1,a+c+1);
    for(int i = 1;i <= c;i++){
        if(a[i]==x){
            p = c+1-i;
            break;
        }
    }
    int l;
    if(p%n==0){
        l = p/n;
    }
    else l = p/n+1;
    if(l%2==1){
        if(p%n==0){
            cout<<l<<" "<<n;
        }
        else cout<<l<<" "<<p%n;
    }
    else{
        if(p%n==0){
            cout<<l<<" 1";
        }
        else{
            cout<<l<<" "<<n+1-(p%n);
        }
    }
	return 0;
}
