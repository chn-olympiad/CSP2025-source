#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int num,sum=0,maxa=0;
    cin>>num;
    int a[num+1];
    for(int i=0;i<num;i++){
        cin>>a[i];
    }
    sort(a,a+num+1);
    maxa=a[num];
    if(num<3){
        cout<<0;
    }else if(num=3 && maxa<=10){
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
