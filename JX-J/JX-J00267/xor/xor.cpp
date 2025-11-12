#include<bits/stdc++.h>
using namespace std;
int a[10] = {1,2,3,4,9,8,7,6};

bool cmp(int x,int y){
    return x < y;
}



int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    sort(a,a+10,cmp);
    for(int i = 0;i < 10;i++){
        cout << a[i];
    }



    return 0;
}
