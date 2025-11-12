#include<bits//stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n = 0;
    int m = 0;
    cin>>n>>m;
    long long s = 1000;
    int a[s] = {};
    cin>>a[s];
    int c = 1;
    int r = 1;
    for(int i = 0;i <='s';i++)
    {
        if(a[0] < a[s])
        {
            r += 1;
        }
        if(r > n)
        {
            c += 1;
        }
    }
    cout<<c<<r<<endl;
}
