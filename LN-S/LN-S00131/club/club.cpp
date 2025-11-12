#include <bits/stdc++.h>
using namespace std;
int n1 ,t ,Maxiii;
int L1[100005] , L2[100005] ,L3[100005];
bool p(int x , int y){
    return x > y;
}
int num(int n){
    sort(L1 , L1+n , p);
    //sort(L2 , L2+n );
    //sort(L3 , L3+n );
    for(int i = 0 ; i < n/2 ; i ++){
        Maxiii = Maxiii + L1[i];
    }
    return Maxiii;
}
int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t ;
    for(int  i0 = 0 ; i0 < t ; i0 ++){
        cin >> n1 ;
        for(int j = 0 ; j < n1 ; j ++)
        {
            cin >> L1[i0] >> L2[i0] >> L3[i0];
        }
        cout << num(n1) << endl;
        }
    return 0;
}
