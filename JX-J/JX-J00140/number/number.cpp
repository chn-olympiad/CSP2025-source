#include<bits/stdc++.h>//48-57
using namespace std;
int num[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string a;
    long long int t=1;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if((int)a[i]>=48 && (int)a[i]<=57){
            num[t]=a[i];
            num[t]-=48;
            t++;
        }
    }
    for(int i=1;i<t;i++){
        for(int j=1;j<t;j++){
            if(num[j]<num[j+1]){
                swap(num[j],num[j+1]);
            }
        }
    }
    for(int i=1;i<t;i++){
        cout<<num[i];
    }

    return 0;
}
