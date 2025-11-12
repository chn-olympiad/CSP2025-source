#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >>n;
    int a[5000];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int s = max(a[0],max(a[1],a[2]));
    if(n<3 or a[0]+a[1]+a[2] <= s){
        cout << 0;
    }else{
        cout << 1;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
