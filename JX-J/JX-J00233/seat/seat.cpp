#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,x,rs,a[N];
int l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    rs=n*m;
    cin>>a[1];
    x=a[1];
    for(int i=2;i<=rs;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+rs);
    for(int i=1;i<=rs;i++)
        if(a[i]==x){
            x=rs+1-i;
            break;
        }
    if(x%n==0) l=x/n;
    else l=x/n+1;
    h=x%n;
    if(h==0) h=n;
    if(l%2==0) h=n+1-h;
    cout<<l<<' '<<h;
    return 0;
}
