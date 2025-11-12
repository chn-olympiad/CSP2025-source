#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //0:48
    char a[1000000];
    int num[1000000],n;
    cin >> a;
    for(int i=0;i<strlen(a);i++){
        if(int(a[i])>=48&&int(a[i])<=57){
            num[n]=int(a[i])-48;
            n++;
        }   
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(num[j]<=num[j+1]){
                swap(num[j],num[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << num[i];
    }
    cout << endl;
    return 0;
}
