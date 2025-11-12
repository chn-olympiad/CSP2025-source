#include<iostream>
#include<algorithm>
using namespace std;
const int N=1145;
int n,m,a[N],R,Ri;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    R=a[1];
    sort(a+1,a+(n*m+1),cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==R){
            Ri=i;
            break;
        }
    int a,b;
    a=(Ri+n-1)/n;
    b=Ri%m;
    if(b==0)b=m;
    if(a%2==0)b=m-b+1;
    cout<<a<<' '<<b;
    return 0;
}
