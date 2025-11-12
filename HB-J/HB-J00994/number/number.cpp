#include<iostream>
#include<string>
using namespace std;
int main(){
    int number[1000001];
    int fuzhu,g;
    string fu;
    int s=0,b=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>fuzhu;
    g=fuzhu;
    for(int i=1000000;i>=1;i++){
        if(fuzhu%i!=0){
            number[i]=fuzhu/i;
            b++;
        }
    }
    for(int i=1;i<=b;i++){
        if(number[i]>=number[i-1]){
            s=number[i];
            number[i]=number[i-1];
            number[i-1]=s;
        }
    }
    for(int i=0;i<=b;i++){
        cout<<number[i];
    }
    return 0;
}
