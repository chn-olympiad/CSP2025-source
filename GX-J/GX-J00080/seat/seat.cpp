#include <iostream>
using namespace std;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int main()
{
    int n,m,a[105],s1,b,x,y;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        s1=a[0];
        if(a[i]<a[i+1]) {
            a[i]=a[i+1];
            if(a[i]==s1){
                b=i;
            }
        }
    }
    x=b/n;
    y=abs(b/n);
    cout<<a[y][x];

    return 0;
}
