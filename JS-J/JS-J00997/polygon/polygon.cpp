#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(n==3)
    {
        if(a[0] + a[1]> a[2])
        {
            cout << 1 << endl;
        }
        else{
            cout << 0<<endl;
        }
    }
    return 0;
}
