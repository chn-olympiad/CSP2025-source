#include <bits/stdc++.h>
using namespace std;
int zhhu(int a){
    if(a==48){
        return 0;
    }else if(a==49){
        return 1;
    }else if(a==50){
        return 2;
    }else if(a==51){
        return 3;
    }else if(a==52){
        return 4;
    }else if(a==53){
        return 5;
    }else if(a==54){
        return 6;
    }else if(a==55){
        return 7;
    }else if(a==56){
        return 8;
    }else if(a==57){
        return 9;
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main (){
    freopen("number.in","r",stdin);
    freopen ("number.out","w",stdout);
    string a;
    int b[1000000];
    cin>>a;
    int z=0;
    for(int i=0;i<a.size();i++){
        if(int(a[i])>=97&&int(a[i])<=122){}
        else {
            b[z]=a[i];
            z++;
        }
    }
    sort(b,b+z,cmp);
    for(int i=0;i<z;i++){
        cout<<zhhu(b[i]);
    }
    return 0;
}
