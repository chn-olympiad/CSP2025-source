#include<bits/stdc++.h>
using namespace std;
long long a[12]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string c;
    cin>>c;
    for(int i=0;i<c.size();i++){
        if(c[i]-'0'==0){
            a[0]++;
        }
        if(c[i]-'0'==1){
            a[1]++;
        }
        if(c[i]-'0'==2){
            a[2]++;
        }
        if(c[i]-'0'==3){
            a[3]++;
        }
        if(c[i]-'0'==4){
            a[4]++;
        }
        if(c[i]-'0'==5){
            a[5]++;
        }
        if(c[i]-'0'==6){
            a[6]++;
        }
        if(c[i]-'0'==7){
            a[7]++;
        }
        if(c[i]-'0'==8){
            a[8]++;
        }
        if(c[i]-'0'==9){
            a[9]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]){
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
