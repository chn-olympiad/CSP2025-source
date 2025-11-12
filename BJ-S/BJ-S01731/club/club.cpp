#include<bits/stdc++.h>
using namespace std;

bool cmp1(int a,int b){
    if (a>b){
        return a;
    }else return b;
}
bool cmpp1(int a1,int a2,int a3){
    int f;
    f = cmp1(a1,a2);
    return cmp1(f,a3);
}
bool cp1(int q1,int q2,int q3,int q4){
    if (q4==q1) return 1;
    if (q4==q2) return 2;
    if (q4==q3) return 3;

}
int main(){
    freopen("club1.in","r",stdin);
    freopen("club1.out","w",stdout);

    int t,n,et,ey;
    int er =0;
    int arr11[1000005];
    int brr22[1000005];
    int crr33[1000005];
    cin>>t;
    for (int i=1;i<=t;i++){
        cin>>n;
        for (int j=1;j<=n;j++){
            cin >> arr11[j] >>brr22[j] >>crr33[j];
            er = er + cmpp1(arr11[j],brr22[j],crr33[j]);
        }

        cout<<er<<"/n";
    }

    return 0;
}

