#include <bits/stdc++.h>
using namespace std;
long long a,b,c[100000],d=a*b,e=0,f,g;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>c[i];
        if(c[i]>c[1]){
            e++;
        }
    }
    sort(c+1,c+d+1);
    g=e%b;
    f=int(e/b)+1;
    if(f%2==0){
        cout<<f<<" "<<b-g;
    }else{
        cout<<f<<" "<<g+1;
    }
    return 0;
}
