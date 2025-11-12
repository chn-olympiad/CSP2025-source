#include<bits/stdc++.h>
using namespace std;
int a,b,seats[100],sign,sp,f;
void makesort(){
    for(int i=a*b-2;i>=0;i--){
        int f=1;
        for(int j=0;j<=i;j++){
            if(seats[j]<seats[j+1]){
                swap(seats[j],seats[j+1]);
                f=0;
            }
        }
        if(f){
            break;
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a*b;i++){
        cin>>seats[i];
    }
    sign=seats[sp];
    makesort();
    for(int i=0;i<a*b;i++){
        if(seats[i]==sign){
            sp=i;
        }
    }
    if((sp/a+1)%2==1){
        cout<<sp/a+1<<" "<<(sp+1)%a;
        return 0;
    }
    cout<<sp/a+1<<" "<<a+1-(sp+1)%a;
    return 0;
}
