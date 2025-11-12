#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","w",stdin);
    freopen("number.out","w",stdout);
    int num[1000001]={0},side=0;
    char a[1000001]={"+"};

    cin>>a;
    for(int i=0;i<1000001;i++){
        if(a[i]==43){
            break;
        }
        if(48<=a[i]&&a[i]<=57){
            side++;
            num[side]=a[i]-48;

        }
    }
    sort(num-1,num+side+1);
    for(int i=side;i>=1;i--){
        cout<<num[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
