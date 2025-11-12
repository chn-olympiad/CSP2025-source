#include<bits/stdc++.h>;
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,h,l,s,e=1;
    cin >> n >> m;
    int c = n*m;
    for(int i = 0;i<=c-1;i++)
    {
        cin >> a[i];
    }
    s = a[0];
    sort(a,a+c);
    for(int i = c-1;i>=0;i--)
    {
        if(a[i] > s)
        {
            e++;
        }
        else
        {
            break;
        }
    }
    l = (e-1)/n + 1;
    if(l % 2 == 0)
    {
        h = n - (e-(l-1)*n) + 1;
    }
    else{
        h = e-(l-1)*n;
    }
    cout << l << " " << h;
}
